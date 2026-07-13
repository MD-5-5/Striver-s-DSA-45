#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class NodeVal {
public:
    int maxNode, minNode, sum;
    NodeVal(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    NodeVal helper(TreeNode* root) {
        if (!root) {
            return NodeVal(INT_MAX, INT_MIN, 0);
        }

        NodeVal left = helper(root->left);
        NodeVal right = helper(root->right);

        // Current subtree is a BST
        if (left.maxNode < root->val && root->val < right.minNode) {

            int curSum = left.sum + right.sum + root->val;
            ans = max(ans, curSum);

            return NodeVal(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                curSum
            );
        }

        // If Not
        return NodeVal(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    Solution obj;
    cout << "Maximum Sum BST = " << obj.maxSumBST(root) << endl;

    return 0;
}




    /*
                1
              /   \
             4     3
            / \   / \
           2   4 2   5
                      / \
                     4   6

        Maximum Sum BST = 20
        (Subtree rooted at 5 => 4 + 5 + 6 + 3 + 2 = 20)
    */
