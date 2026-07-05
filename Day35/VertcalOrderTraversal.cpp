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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> todo;

        // {Node, {Vertical, Level}}
        todo.push({root,{0,0}});

        while(!todo.empty()){

            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }

            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto p : nodes){

            vector<int> col;

            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

int main(){

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.verticalTraversal(root);

    cout << "Vertical Traversal :" << endl;

    for(auto col : ans){
        for(auto x : col){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}