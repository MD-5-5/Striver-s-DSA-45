#include<bits/stdc++.h>
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
    TreeNode* helper(vector<int>& arr, int lo, int hi) {
        if (lo > hi)
            return NULL;

        int mid = lo + (hi - lo) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = helper(arr, lo, mid - 1);
        root->right = helper(arr, mid + 1, hi);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& arr) {
        return helper(arr, 0, arr.size() - 1);
    }
};

// Level Order Traversal
void levelOrder(TreeNode* root) {
    if (root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        cout << endl;
    }
}

int main() {

    vector<int> arr = {-10, -3, 0, 5, 9};

    Solution obj;
    TreeNode* root = obj.sortedArrayToBST(arr);

    cout << "Level Order Traversal of BST: "<<endl;
    levelOrder(root);

    return 0;
}