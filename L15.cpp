#if 0

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        map<int, int>mp;
        if (nums.size() <= 2)return result;
        int len = nums.size();
        for (int i = 0; i < len; i++)
            mp[nums[i]]++;
        for (auto& it : mp) {
            it.second--;
            for (auto& it2 : mp) {
                if (it2.first < it.first) continue;
                if (it2.second <= 0)continue;
                it2.second--;
                int tmp =  - it.first - it2.first;
                auto k = mp.find(tmp);
                if (k == mp.end()|| k->first<it2.first) {
                    it2.second++; continue;
                }
                if (k->second)
                    result.push_back({ it.first,it2.first,tmp });
                it2.second++;
            }
            it.second++;
        }
        return result;
    };
};

int main() {
    vector<int>nums = { -1,0,1,2,-1,-4 };
    Solution a;
    auto result = a.threeSum(nums);
    for (auto its : result) {
        cout << endl;
        for(auto it:its) {
            cout << it << " ";
        }
    }
}

#endif