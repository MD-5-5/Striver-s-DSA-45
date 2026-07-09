// Children Sum Property :
// For every node => node->val = left->val + right->val
//
// You are allowed to increase the value of any node
// by any positive amount, any number of times.
// Decreasing any node's value is NOT allowed.

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
    void childSum(TreeNode* root) {
        if (root == nullptr)
            return;

        int child = 0;

        if (root->left)
            child += root->left->val;

        if (root->right)
            child += root->right->val;

        if (child >= root->val) {
            root->val = child;
        } else {
            if (root->left)
                root->left->val = root->val;

            if (root->right)
                root->right->val = root->val;
        }

        childSum(root->left);
        childSum(root->right);

        int total = 0;

        if (root->left)
            total += root->left->val;

        if (root->right)
            total += root->right->val;

        if (root->left || root->right)
            root->val = total;
    }
};

void inorder(TreeNode* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(7);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    Solution obj;

    cout << "Before Conversion : ";
    inorder(root);
    cout << endl;

    obj.childSum(root);

    cout << "After Conversion : ";
    inorder(root);
    cout << endl;

    return 0;
}

// TC = O(n);
// SC = O(h); h => height of tree;