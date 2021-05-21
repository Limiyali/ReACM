#if 1
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string>result;
    string mp[10];
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pgrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        char r[5] = { 0 };
        dfs(digits,r,0);
        return result;

    }
    void dfs(string s,char*r,int depth){
        if(s.length()==0){
            result.push_back(string(r));
            return;
        }
        int dig = s[0]-'0';
        for(int i=0;i<mp[dig].length();i++){
            r[depth]=mp[dig][i];
            dfs(&s[1],r,depth+1);
        }
    }
};

int main() {
    Solution a;
    auto result = a.letterCombinations("23");
    for (auto its : result) {
        cout << its << endl;
    }
}

#endif