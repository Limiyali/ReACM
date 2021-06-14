#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
        int len = s.length();
        vector<int>dp(len,0);
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            cnt++;
            for (int j = 0; j < i; j++) {
                if (s[j] == s[i] && dp[j + 1]) {
                    dp[j] = 1;
                    cnt++;
                }
                else dp[j] = 0;
            }
        }
        return cnt;
    }
};

int main() {
    Solution a;
    cout << a.countSubstrings("aaa");
}


#endif