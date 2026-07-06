#include <bits/stdc++.h>
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root == p || root == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        //we found our root which was given to operate
        return root;
    }
}
int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* p = root->left->left;      
    // Node 4
    TreeNode* q = root->left->right;     
    // Node 5
        TreeNode* ans = lowestCommonAncestor(root, p, q);
        cout << ans->val << endl;

    return 0;
}