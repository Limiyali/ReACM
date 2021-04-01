#if 0
#include <iostream>

using namespace std;


int main() {
	int T, n;
	int temp;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int oneN = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			oneN ^= temp;
		}
		if (oneN)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
#endif