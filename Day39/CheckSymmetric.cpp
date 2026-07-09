#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool isTrue(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (leftRoot == NULL && rightRoot == NULL)
            return true;

        if ((leftRoot == NULL && rightRoot != NULL) ||
            (leftRoot != NULL && rightRoot == NULL))
            return false;

        if (leftRoot->val != rightRoot->val)
            return false;

        return isTrue(leftRoot->left, rightRoot->right) &&
               isTrue(leftRoot->right, rightRoot->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isTrue(root->left, root->right);
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is Not Symmetric" << endl;
    return 0;
}