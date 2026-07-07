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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) {
            return nullptr;
        }

        int rootVal = preorder[idx];
        int i;

        for (i = start; i <= end; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
        }

        idx++;

        TreeNode* root = new TreeNode(rootVal);

        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;

        return solve(preorder, inorder, 0, n - 1, idx);
    }
};


int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    return 0;
}