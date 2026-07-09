#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left != NULL) {

                // Save the right subtree
                TreeNode* r = curr->right;

                // Move left subtree to right
                curr->right = curr->left;

                // Find the rightmost node of left subtree
                TreeNode* pred = curr->left;
                while (pred->right != NULL)
                    pred = pred->right;

                // Attach the original right subtree
                pred->right = r;

                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        // Remove all left pointers
        TreeNode* temp = root;
        while (temp != NULL) {
            temp->left = NULL;
            temp = temp->right;
        }
    }
};

void printFlattened(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;
    obj.flatten(root);

    cout << "Flattened Tree: ";
    printFlattened(root);

    return 0;
}