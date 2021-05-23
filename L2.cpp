#if 0
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1 = l1, * pre1, * pre2;
        ListNode* current2 = l2;
        int jin = 0;
        while (true) {
            current1->val += current2->val;
            current1->val += jin;
            jin = 0;
            if (current1->val >= 10) {
                current1->val -= 10;
                jin = 1;
            }
            pre1 = current1;
            pre2 = current2;
            current1 = current1->next;
            current2 = current2->next;
            if (current1 == nullptr && current2 == nullptr)break;
            if (current1 == nullptr) pre1->next = current1 = new ListNode(0);
            if (current2 == nullptr) pre2->next = current2 = new ListNode(0);
        }
        if (jin > 0) {
            ListNode* last = new ListNode(jin);
            pre1->next = last;
        }
        return l1;
    }
};

int main() {
    return 0;
}


#endif