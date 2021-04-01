#if 0
#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;

#pragma warning(disable:4996)
int main() {
	int n;
	cin >> n;
	stack<int>s;
	vector<int>a(n);
	vector<int>result(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && a[s.top()] <= a[i]) s.pop();
		result[i] = (s.empty() )? -1 : s.top();
		s.push(i);
	}
	for (int it : result)
		cout << it+1 << " ";
}


#endif