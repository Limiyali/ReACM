#if 0
#include <iostream>
#include <cstdio>
using namespace std;
int Num[100001];

void quicksort(int* num, int start, int end) {
	if (start >= end)return;
	int n0 = num[start];
	int i = start, j = end;
	while (i < j) {
		while (num[j] >= n0 && j> i) j--;
		num[i] = num[j];
		while (num[i] <= n0 && j>i) i++;
		num[j] = num[i];
	}
	num[i] = n0;
	quicksort(num, start, i - 1);
	quicksort(num, i + 1, end);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &Num[i]);
	quicksort(Num, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", Num[i]);
}

#endif // 1
