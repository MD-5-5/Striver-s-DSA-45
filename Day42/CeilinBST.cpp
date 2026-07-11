#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left=right=NULL;
    }
};
int SearchCeil(TreeNode* root, int val){
    int ceilVal = -1;
    while(root){
        if(root->val == val){
            return root->val;
        }

        if(val < root->val){
            ceilVal = root->val;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ceilVal;
}


int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    int val = 7;
    cout<<SearchCeil(root,val);
    
}