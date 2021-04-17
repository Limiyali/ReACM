#if 0
#include <iostream>
#include <algorithm>
using namespace std;
int num[100005], result[100005];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> num[i], result[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (num[i] > num[j]) {
				result[i] = max(result[i], result[j] + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << result[i] << endl;
}

#endif