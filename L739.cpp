#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>dp(temperatures.size());
        int len = temperatures.size();
        for (int i = temperatures.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j += dp[j]) {
                if (temperatures[i] < temperatures[j]) {
                    dp[i] = j - i;
                    break;
                }
                else if (dp[j] == 0) {
                    dp[i] = 0;
                    break;
                }
            }
        }
        return dp;
    }
};

int main() {

}


#endif