#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true; // false -> inorder, true -> reverse inorder

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushEvery(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (!reverse)
            pushEvery(temp->right);
        else
            pushEvery(temp->left);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushEvery(TreeNode* root) {
        while (root != NULL) {
            st.push(root);

            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, false); // smallest
        BSTIterator right(root, true); // largest

        int i = left.next();
        int j = right.next();

        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = left.next();
            else
                j = right.next();
        }

        return false;
    }
};

int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    Solution obj;

    int k = 9; 

    if (obj.findTarget(root, k))
        cout << "True";
    else
        cout << "False";

    return 0;
}