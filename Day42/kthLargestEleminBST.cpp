#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

void reverseInorder(TreeNode* root, int k, int &count, int &ans){
    if(root == NULL) return;

    reverseInorder(root->right, k, count, ans);

    count++;
    if(count == k){
        ans = root->val;
        return;
    }

    reverseInorder(root->left, k, count, ans);
}

int kthLargest(TreeNode* root, int k){
    int count = 0;
    int ans = -1;

    reverseInorder(root, k, count, ans);

    return ans;
}

int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 2;

    cout << kthLargest(root, k);
}