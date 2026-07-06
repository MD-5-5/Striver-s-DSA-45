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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        bool checkDirection = true; // Left -> Right

        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int idx = (checkDirection) ? i : (size - 1 - i);

                row[idx] = node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            checkDirection = !checkDirection;
            res.push_back(row);
        }

        return res;
    }
};

int main() {
    
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> ans = obj.zigzagLevelOrder(root);
    for (auto level : ans) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}