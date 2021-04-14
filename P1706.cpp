#if 0
#include <iostream>
using namespace std;
int num[9], result[9], vis[9];
int n;

void dfs(int deep) {
	if (deep == n) {
		for (int i = 0; i < n; i++) {
			cout << "    " << result[i];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		vis[i] = 1;
		result[deep] = num[i];
		dfs(deep + 1);
		vis[i] = 0;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		num[i] = i + 1;
	dfs(0);
	return 0;
}
#endif // 1
