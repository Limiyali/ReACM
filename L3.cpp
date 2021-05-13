#if 1
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>flag;
        int result = 0;
        int len = s.length();
        int start = 0;
        for (int i = 0; i < len; i++) {
            if (flag[s[i]] > 0) {
                int repeat = flag[s[i]];
                for (int j = start; j < repeat; j++)
                    flag[s[j]] = 0;
                start = repeat;
            }
            flag[s[i]] = i + 1;
            result = max(result, i + 1 - start);
        }
        return result;
    }
};


int main() {
    string s = "123";
    cout << s.length();
}


#endif