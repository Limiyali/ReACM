#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
        int longestValidParentheses(string s) {
        int maxlen = 0;
        int templen=0;
        int len  = s.length();
        int pre=0;
        for(int i=0;i<len;i++){
            if(s[i]==')') pre -=1;
            else pre +=1;
            if(pre<0){
                maxlen = max(maxlen,templen);
                templen = 0;
                pre = 0;
            }else if(pre == 0){
                templen++;
                maxlen = max(maxlen,templen);
            }
            else templen++;
        }
        pre = 0;
        templen = 0;
        for(int i=len-1;i>=0;i--){
            if(s[i]==')') pre +=1;
            else pre -=1;
            if(pre<0){
                maxlen = max(maxlen,templen);
                templen = 0;
                pre = 0;
            }else if(pre == 0){
                templen++;
                 maxlen = max(maxlen,templen);
            }
            else templen++;
        }
        return maxlen;

    }
};

int main() {
    Solution a;
    cout << a.isMatch("aab","c*a*b") << endl;
}
#endif