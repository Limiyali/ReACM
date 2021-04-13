#if 0
#include <iostream>
using namespace std;
int num[500001];
int n, m;


void update(int x, int val) {
	while (x <= n) {
		num[x] += val;
		x += (x & -x);
	}
}

int getSum(int end) {
	int ans = 0;
	while (end != 0) {
		ans += num[end];
		end -= (end & -end);
	}
	return ans;
}

int main() {

	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		update(i + 1, temp);
	}
	int catgory, arg1, arg2;
	for (int i = 0; i < m; i++) {
		cin >> catgory >> arg1 >> arg2;
		if (catgory == 1)
			update(arg1, arg2);
		else
			cout << getSum(arg2) - getSum(arg1 - 1) << endl;
	}
		
}


#endif