#if 0
#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>
#include <set>
#include <list>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int m_min = 0x7fffffff;
        int m_max = -m_min;
        int len = nums.size();
        int max_r=0,min_r = len-1;
        vector<int>mins(len);
        vector<int>maxs(len);
        for(int i=0;i<len;i++){
            if(m_max<nums[i])
                m_max=nums[i];
            maxs[i]=m_max;
        }
        for(int i=len-1;i>=0;i--){
            if(m_min>nums[i])
                m_min=nums[i];
            mins[i]=m_min;
        }
        for(int i=0;i<len;i++){
            if(mins[i]!=nums[i]){
                min_r = i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(maxs[i]!=nums[i]){
                max_r=i;
                break;
            }
        }
        return max(max_r-min_r+1,0);

    }
};

template<typename t>
void pt(t& a) {
    for (auto& it : a) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    ostream_iterator<int>o{ cout," " };
    forward_list<int>a;
    for (int i = 0; i < 10; i++)
        a.push_front(i);
    copy(a.begin(), a.end(), o);


}


#endif