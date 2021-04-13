#if 0
#include<iostream>
#include <cstdio>
using namespace std;

long long quickPow(long long  b, long long  p, long long k) {
	long long result = 1;
	while (p) {
		if (p & 1)
			result = (result * b) % k;
		b = (b * b) % k;
		p >>= 1;
	}
	return result % k;
}


int main() {
	int b, p, k;
	cin >> b >> p >> k;
	printf("%d^%d mod %d=%ld", b, p, k, quickPow(b, p, k));
}


#endif // 1
