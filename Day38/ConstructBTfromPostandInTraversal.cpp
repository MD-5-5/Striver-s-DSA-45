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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) {
            return nullptr;
        }

        int rootVal = postorder[idx];
        int i;

        for (i = start; i <= end; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
        }

        idx--;

        TreeNode* root = new TreeNode(rootVal);

        root->right = solve(postorder, inorder, i + 1, end, idx);

        root->left = solve(postorder, inorder, start, i - 1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        int idx = postorder.size() - 1;
        return solve(postorder, inorder, 0, inorder.size() - 1, idx);
    }
};

//Check
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(postorder, inorder);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}