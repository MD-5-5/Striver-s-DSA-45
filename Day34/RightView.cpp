#include <iostream>
#include <vector>
#include <algorithm>
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

    // Height of tree
    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    //Right View 
    void rightPreOrder(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) return;

        ans[level] = root->val;

        rightPreOrder(root->left, ans, level + 1);
        rightPreOrder(root->right, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);
        rightPreOrder(root, ans, 0);
        return ans;
    }

    // Left View 
    void leftPreOrder(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) return;

            ans[level] = root->val;

        leftPreOrder(root->right, ans, level + 1);
        leftPreOrder(root->left, ans, level + 1);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);
        leftPreOrder(root, ans, 0);
        return ans;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
             \
              7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->right->right = new TreeNode(7);

    Solution obj;

    vector<int> left = obj.leftSideView(root);
    vector<int> right = obj.rightSideView(root);

    cout << "Left View : ";
    for (int x : left)
        cout << x << " ";

    cout << endl;

    cout << "Right View: ";
    for (int x : right)
        cout << x << " ";

    cout << endl;

    return 0;
}