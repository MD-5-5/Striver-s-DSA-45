#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long long mini, long long maxi) {
        if (root == NULL)
            return true;

        if (root->val <= mini || root->val >= maxi)
            return false;

        return isValidBST(root->left, mini, root->val) &&
               isValidBST(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;
    if (obj.isValidBST(root))
        cout <<"Valid BST ";
    else
        cout << "Not a Valid BST";

    return 0;
}