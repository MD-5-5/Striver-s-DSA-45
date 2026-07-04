#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {

            // Case 1: No left child
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // Find preorder predecessor
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                // First visit
                if (pred->right == NULL) {
                    ans.push_back(curr->val);   
                    pred->right = curr;         // Create thread
                    curr = curr->left;
                }
                // Second visit
                else {
                    pred->right = NULL;         // Remove thread
                    curr = curr->right;
                }
            }
        }

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

    cout << "Morris Preorder Traversal: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}