#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi) {

        if (prelo > prehi)
            return NULL;

        TreeNode* root = new TreeNode(pre[prelo]);

        if (prelo == prehi)
            return root;

        int i = inlo;
        while (i <= inhi) {
            if (in[i] == pre[prelo])
                break;
            i++;
        }

        int leftCount = i - inlo;

        root->left = build(pre, prelo + 1, prelo + leftCount,in, inlo, i - 1);
        root->right = build(pre, prelo + leftCount + 1, prehi,in, i + 1, inhi);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in = pre;
        sort(in.begin(), in.end());

        int n = pre.size();
        return build(pre, 0, n - 1, in, 0, n - 1);
    }
};

void preorder(TreeNode* root) {
    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorderInput = {8, 5, 1, 7, 10, 12};

    Solution obj;
    TreeNode* root = obj.bstFromPreorder(preorderInput);

    cout << "Preorder of Constructed BST: ";
    preorder(root);
    cout << endl;
    cout << "Inorder of Constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}