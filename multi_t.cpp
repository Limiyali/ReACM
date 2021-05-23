#if 1
#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <future>
#include <atomic>
#include <deque>
#include <algorithm>
#include <numeric>
#include <condition_variable>
using namespace std;
mutex m;

void proc(int a = 0) {
	cout << " id :" << this_thread::get_id() << " para :" << a << endl;
	Sleep(3000);
	cout << "sleep finished\n";
}

void proc1() {
	lock_guard<mutex> g1(m);
	cout << "in proc1\n";
	Sleep(3000);
	cout << "proc1 sleep finished\n";
}

void proc2() {
	m.lock();
	cout << "in proc2\n";
	Sleep(3000);
	cout << "proc2 sleep finished\n";
	m.unlock();
}

void proc3() {
	unique_lock<mutex> g1(m,try_to_lock);
	if (g1.owns_lock()) {
		cout << "in proc3\n";
		Sleep(3000);
		cout << "proc3 sleep finished\n";
	}
	else {
		cout << "no lock\n";
	}
}

double t1(double a, double b) {
	cout << "in t1\n";
	Sleep(3000);
	cout << "finished t1\n";
	return a + b;
}

atomic<int> index(0);

void t2() {
	for (int i = 0; i < 5; i++) {
		index++;
		cout << index << endl;
	}
}
deque<int> q;
mutex mu;
condition_variable cond;
int c = 0;//�������Ĳ�Ʒ����

void producer() {
	int data1;
	while (1) {//ͨ�����ѭ�����ܱ�֤������ֹͣ
		if (c < 3) {//����
			{
				data1 = rand();
				unique_lock<mutex> locker(mu);//��
				q.push_front(data1);
				cout << "����" << data1 << endl;
				cond.notify_one();  // ֪ͨȡ
				++c;
			}
			Sleep(1500);
		}
	}
}

void consumer() {
	int data2;//data�������Ǵ��ȡ������
	while (1) {
		{
			unique_lock<mutex> locker(mu);
			while (q.empty())
				cond.wait(locker); //wait()����ǰ�Ȼ����,�����������߲��ܻ�������Ų�Ʒ����������������notify�󣬽��������������Զ��ֻ��������
			data2 = q.back();//ȡ�ĵ�һ��
			q.pop_back();//ȡ�ĵڶ���
			cout << "ȡ��" << data2 << endl;
			--c;
		}
		Sleep(500);
	}
}

void f(int i= 2) {
	cout << i << endl;
}

thread g() {
	return thread(f,32);
}

template<typename Iterator,typename T>
struct accumulate_block {
	void operator()(Iterator first, Iterator end, T& res) {
		res = accumulate(first, end, res);
	}
};

template<typename T,typename Iterator>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
  const unsigned long len = distance(first, last);
  if (!len) return init;
  const unsigned long min_per_thread = 25;
  const unsigned long max_threads = (len + min_per_thread - 1) / min_per_thread;
  const unsigned long hardware_threads = std::thread::hardware_concurrency();
  const unsigned long num_threads = min((hardware_threads != 0 ? hardware_threads : 2), max_threads);
  const unsigned long block_size = len / num_threads; // ÿ���߳��е�������
  std::vector<T> res(num_threads);
  std::vector<std::thread> threads(num_threads - 1); // ����һ�����̣߳�������һ���߳�
  Iterator block_start = first;
  for (unsigned long i = 0; i < num_threads - 1; ++i)
  {
    Iterator block_end = block_start;
    std::advance(block_end, block_size); // block_endָ��ǰ���β��
    threads[i] = std::thread(accumulate_block<Iterator, T>{},
      block_start, block_end, std::ref(res[i]));
    block_start = block_end;
  }
  accumulate_block<Iterator, T>()(block_start, last, res[num_threads - 1]);
  for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
  return accumulate(res.begin(), res.end(), init);
}

int main() {
	vector<long long int>a(1000000);
	for (long long int i = 0; i < 10000000000; i++)
		a.push_back(i);
	cout << accumulate<>(a.begin(), a.end(), (long long)0) << endl;
	cout << parallel_accumulate(a.begin(), a.end(), (long long )0) << endl;
	return 0;
}

#endif