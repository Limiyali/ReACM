#if 0
#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <future>
#include <atomic>
#include <deque>
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

int main() {
	cout << add(12, 22);
	cout << "main finished\n";
	return 0;
}

#endif