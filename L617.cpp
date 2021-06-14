#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr) return root2;
        else if(root2==nullptr) return root1;
        root1->val+=root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }
    void pt(TreeNode* root, int n = 0, char flag = '-') {
        if (root) {
            pt(root->right,n+2);
            for (int i = 0; i < n; i++)cout << flag;
            cout << " " << root->val << endl;
            pt(root->left,n+2);
        }
    }
};

int main() {
    Solution r;
    TreeNode a(1), b(2);
    a.left = new TreeNode(3);
    a.right = new TreeNode(2);
    a.left->left = new TreeNode(5);
    r.pt(&a);
    TreeNode * result = r.mergeTrees(&a, &b);
    r.pt(result);
}


#endif