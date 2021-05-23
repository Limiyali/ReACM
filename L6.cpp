#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<vector<char>> tmp(numRows + 1);
        int fac = numRows + numRows - 2;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int cov = (i) % fac + 1;
            if (cov <= numRows)
                tmp[cov].push_back(s[i]);
            else
                tmp[2 * numRows - cov].push_back(s[i]);
        }
        string result;
        for (auto characters : tmp) {
            for (auto character : characters) result.append(&character,1);
        }
        return result;
    }
};

int main() {
    Solution a;
    cout << a.convert("AB",2) << endl;
}
#endif