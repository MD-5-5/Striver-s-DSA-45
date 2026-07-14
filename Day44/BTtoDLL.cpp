#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        TreeNode* curr = root;

        //Singly Linked List
        while (curr != NULL) {

            if (curr->left != NULL) {

                TreeNode* pred = curr->left;

                while (pred->right != NULL)
                    pred = pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }

        // Doubly Linked List bana diya
        TreeNode* prev = NULL;
        curr = root;

        while (curr != NULL) {
            curr->left = prev;
            prev = curr;
            curr = curr->right;
        }
    }
};

void printForward(TreeNode* head) {
    cout << "Forward DLL : ";

    TreeNode* last = NULL;

    while (head != NULL) {
        cout << head->val << " ";
        last = head;
        head = head->right;
    }

    cout << endl;
    cout << "Backward DLL: ";
    while (last != NULL) {
        cout << last->val << " ";
        last = last->left;
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

    printForward(root);

    return 0;
}