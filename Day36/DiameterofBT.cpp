#include <iostream>
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

    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(levels(root->left), levels(root->right));
    }
    void helper(TreeNode* root, int &maxDia) {
        if (root == NULL)
            return;

        int dia = levels(root->left) + levels(root->right);

        maxDia = max(maxDia, dia);

        helper(root->left, maxDia);
        helper(root->right, maxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};

int main() {

    //          1
    //        /   \
    //       2     3
    //      / \     
    //     4   5
    // Diameter = 3 (4 -> 2 -> 1 -> 3)

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution obj;

    cout << "Diameter of Binary Tree = " << obj.diameterOfBinaryTree(root);

    return 0;
}