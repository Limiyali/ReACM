#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, num = 1;
        int maxlen = 1;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = 1;; j++) {
                if (i - j < 0 || i + j >= len) break;
                if (s[i - j] == s[i + j]) {
                    if (maxlen < (2 * j + 1)) {
                        maxlen = 2 * j + 1;
                        start = i - j;
                        num =  2*j + 1;
                    }
                }
                else break;
            }
            if (i+1<len && s[i] != s[i + 1])continue;
            if (maxlen < 2) {
                maxlen = 2;
                start = i;
                num = 2;
            }
            for (int j = 1;; j++) {
                if (i - j < 0 || i + j +1>= len) break;
                if (s[i - j] == s[i + j+1]) {
                    if (maxlen < (2 * j + 2)) {
                        maxlen = 2 * j + 2;
                        start = i - j;
                        num = 2*j+2;
                    }
                }
                else break;
            }
        }
        return s.substr(start, num);
    }
};

int main() {
    Solution a;
    cout << a.longestPalindrome("cbbd") << endl;
}
#endif