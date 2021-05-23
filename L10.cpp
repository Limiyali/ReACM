#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char *s,const char* p) {
        if (*p == 0) return *s == 0;
        bool first_match = *s && (p[0] == '.' || p[0] == s[0]);
        if (p[1] == '*') {
            return isMatch(s, p+2) || (first_match && isMatch(s+1, p));
        }
        else
            return first_match && isMatch(s+1, p+1);
    }
};

int main() {
    Solution a;
    cout << a.isMatch("aab","c*a*b") << endl;
}
#endif