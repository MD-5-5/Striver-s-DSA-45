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
int SearchFloor(TreeNode* root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){
            return root->val;
        }

        if(key > root->val){
            floor = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
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
    int key = 7;
    cout<<SearchFloor(root,key);
    
}