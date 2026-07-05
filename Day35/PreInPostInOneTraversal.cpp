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
    vector<vector<int>> preInPostTraversal(TreeNode* root){
        stack<pair<TreeNode*, int>> st;
        st.push({root,1});
        vector<int> pre,in,post;
        if(root == NULL) return {};
        while(!st.empty()){
            auto it = st.top();
            st.pop();

            // For PreOrder
            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left != NULL){
                    st.push({it.first->left,1});
                }
            }

            //For Inorder
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right != NULL){
                    st.push({it.first->right,1});
                }
            }

            //For PostOrder
            else{
                post.push_back(it.first->val);
            }
        }
        return {pre, in, post};
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution obj;
    vector<vector<int>> ans = obj.preInPostTraversal(root);

    cout << "Pre Traversal : ";
    for (int x : ans[0])
        cout << x << " ";

    cout << endl;

    cout << "In Traversal : ";
    for (int x : ans[1])
        cout << x << " ";

    cout << endl;

    cout << "Post Traversal : ";
    for (int x : ans[2])
        cout << x << " ";

    cout << endl;

    return 0;

}
