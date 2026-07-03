#include <bits/stdc++.h>
using namespace std;
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
    void PreOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);   // Root
        PreOrder(root->left, ans);  // Left
        PreOrder(root->right, ans); // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        PreOrder(root, ans);
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
    vector<int> ans = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}