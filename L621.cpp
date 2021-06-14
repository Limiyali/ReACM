#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int num[26] = { 0 };
        for (auto& it : tasks)
            num[it - 'A']++;
        sort(num, num + 26, greater<int>());
        int recount = (num[0] - 1) * (n + 1) + 1;
        for (int i = 1; i < 26; i++) {
            if (num[0] == num[i])
                recount++;
        }
        return max(recount, (int)tasks.size());
    }
};

int main() {
    Solution a;
    vector<char>t = { 'A','A','A','B','B','B' };
    cout << a.leastInterval(t,2);
}


#endif