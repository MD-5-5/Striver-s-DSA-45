#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    map<int, pair<int, int>> mp; // hd -> {level, value}

    void dfs(TreeNode* root, int hd, int level) {
        if (root == NULL) return;

        // Store the deepest node for each HD

        if (mp.find(hd) == mp.end() || level >= mp[hd].first)
        mp[hd] = {level, root->val};
        
        dfs(root->left, hd - 1, level + 1);
        dfs(root->right, hd + 1, level + 1);
    }

    vector<int> bottomView(TreeNode* root) {

        vector<int> ans;
        dfs(root, 0, 0);

        for (auto x : mp)
            ans.push_back(x.second.second);

        return ans;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.bottomView(root);

    cout << "Bottom View: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}