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

class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushEvery(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        pushEvery(temp->right);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushEvery(TreeNode* root) {
        for (; root != nullptr; st.push(root), root = root->left);
    }
};

int main() {

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    cout << "BST Iterator Output"<<endl;

    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}