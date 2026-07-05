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
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        int ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){

            int size = q.size();

            long long mini = q.front().second;

            long long first, last;

            for(int i = 0; i < size; i++){

                long long curri = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0)
                    first = curri;

                if(i == size - 1)
                    last = curri;

                if(node->left){
                    q.push({node->left, curri * 2 + 1});
                }

                if(node->right){
                    q.push({node->right, curri * 2 + 2});
                }
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
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

    cout << "Maximum Width of Binary Tree = " << obj.widthOfBinaryTree(root);

    return 0;
}