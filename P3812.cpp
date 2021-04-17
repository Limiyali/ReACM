#if 1
#include <iostream>
#include <algorithm>
using namespace std;
int num[51];
long long base[61];

void ins(long long x) {
	for (int i = 60; i >= 0; i--) {
		long long one = 1;
		if (x & (one<< i)) {
			if (!base[i]) {
				base[i] = x;
				return;
			}
			x ^= base[i];
		}
	}
}

bool check(long long x) {
	long long one = 1;
	for (int i = 60; i >= 0; i--) {
		if (x & (one << i)) {
			if (!base[i])return false;
			x ^= base[i];
		}
	}
	return true;
}

long long qMax(long long res = 0) {
	for (int i = 60; i >= 0; i--)
		res = max(res, res ^ base[i]);
	return res;
}

long long qMi(long long res = 0) {
	for (int i = 0; i <= 60; i++)
		if (base[i]) return base[i];
}


int main() {
	int n;
	cin >> n;
	long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ins(temp);
	}
	cout << check(3);
}

#endif // 1
