#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left=right=NULL;
    }
};

class Solution {
public:
    int maxSum;

    int solve(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int both = left + right + root->val;          // Path passes through root
        int anyone = max(left, right) + root->val;    // Continue through one child
        int rootOnly = root->val;                     // Start a new path from root

        maxSum = max({maxSum, both, anyone, rootOnly});

        return max(anyone, rootOnly);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

int main() {
    /*
            -10
           /   \
          9     20
               /  \
              15   7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << obj.maxPathSum(root) << endl;

    return 0;
}