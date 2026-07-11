#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void findPreSuc(TreeNode* root, TreeNode* p,
                    TreeNode*& pre, TreeNode*& suc) {
                    pre = nullptr;
                    suc = nullptr;
        TreeNode* curr = root;

        // Finding Predecessor
        while (curr) {
            if (p->val <= curr->val) {
                curr = curr->left;
            } else {
                pre = curr;
                curr = curr->right;
            }
        }

        curr = root;

        // Finding Successor
        while (curr) {
            if (p->val >= curr->val) {
                curr = curr->right;
            } else {
                suc = curr;
                curr = curr->left;
            }
        }
    }
};

void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    TreeNode* p = root->right; 
    TreeNode* pre = nullptr;
    TreeNode* suc = nullptr;

    Solution obj;
    obj.findPreSuc(root, p, pre, suc);

    if (pre)
        cout << "Predecessor: " << pre->val << endl;
    else
        cout << "Predecessor: NULL" << endl;

    if (suc)
        cout << "Successor: " << suc->val << endl;
    else
        cout << "Successor: NULL" << endl;

    return 0;
}