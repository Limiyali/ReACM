#if 0
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int>tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp.insert(pair<int, int>(nums[i], i));
        }
        int n1, n2;
        int t1, t2;
        for (int i = 0; i < nums.size(); i++) {
            n1 = nums[i];
            n2 = target - n1;
            auto itnum = tmp.count(n2);
            auto it = tmp.find(n2);
            while (itnum) {
                if (it->second != i) {
                    t1 = i;
                    t2 = it->second;
                    break;
                }
                itnum--;
                it++;
            }
        }
        vector<int>result;
        result.push_back(t1);
        result.push_back(t2);
        return result;
    }
};

int main() {
    Solution a;
    vector<int>num = { 2,7,11,5 };
    auto result = a.twoSum(num, 9);
    for (auto it : result) {
        cout << it << endl;
    }
}


#endif