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

class Solution{
public:

    bool getPath(TreeNode* root, vector<int>& arr, int x){

        if(root == NULL)
            return false;

        arr.push_back(root->val);

        if(root->val == x)
            return true;

        if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back();

        return false;
    }

    vector<int> solve(TreeNode* root, int x){

        vector<int> arr;

        if(root == NULL)
            return arr;

        getPath(root, arr, x);

        return arr;
    }
};

int main(){

    /*
                 1
               /   \
              2     3
             /       \
            4         7
           /           \
          8             15
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->right->right->right = new TreeNode(15);

    Solution obj;

    int target = 15;

    vector<int> path = obj.solve(root, target);

    cout << "Path from Root : "<< target << " : ";

    for(int x : path){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}