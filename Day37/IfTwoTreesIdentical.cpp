#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return (p == q);
        }

        return (p->val == q->val) 
        &&
        isSameTree(p->left, q->left) 
        &&
        isSameTree(p->right, q->right);
    }
};

int main() {

    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(root1, root2))
        cout << "Same Tree";
    else
        cout << "Not Same Tree";

    return 0;
}