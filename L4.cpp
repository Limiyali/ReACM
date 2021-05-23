#if 0
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merge;
        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0;
        for (; i < len1 && j < len2;) {
            if (nums1[i] < nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            }
            else {
                merge.push_back(nums2[j]);
                j++;
            }
        }
        for (; i < len1; i++)
            merge.push_back(nums1[i]);
        for (; j < len2; j++)
            merge.push_back(nums2[j]);
        if (merge.size() & 1) {
            return merge[merge.size() / 2];
        }
        else return (merge[merge.size() / 2] + merge[(merge.size() / 2) - 1]) / 2.0;
    }
};


int main() {
    Solution a;
    vector<int> n1 = { 1,2 };
    vector<int>n2 = { 3,4 };
    cout << a.findMedianSortedArrays(n1, n2);

}


#endif