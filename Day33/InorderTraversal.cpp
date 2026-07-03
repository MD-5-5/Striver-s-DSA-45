#include <bits/stdc++.h>
using namespace std;

// Defining binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void InOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        InOrder(root->left, ans);   // Left
        ans.push_back(root->val);   // Root
        InOrder(root->right, ans);  // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        InOrder(root, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);
    Solution obj;
    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}