#include <iostream>
#include <cmath>
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
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lefti = dfs(root->left);
        if (lefti == -1)
            return -1;

        int righti = dfs(root->right);
        if (righti == -1)
            return -1;

        if (abs(lefti - righti) > 1)
            return -1;
        return 1 + max(lefti, righti);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};

int main() {
    //
    //         1
    //       /   \
    //      2     3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    Solution obj;
    if (obj.isBalanced(root))
        cout << "Tree is Balanced";


    else
        cout << "Tree is Not Balanced";
    return 0;
}