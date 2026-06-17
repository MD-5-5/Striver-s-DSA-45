#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination(vector<vector<int>>& ans,
                     vector<int> v,
                     vector<int>& candidates,
                     int target,
                     int idx) {

        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (target < 0)
            return;

        for (int i = idx; i < candidates.size(); i++) {
            v.push_back(candidates[i]);

            // Same element ko dubara use kar sakte hain
            combination(ans, v, candidates,
                        target - candidates[i], i);

            v.pop_back(); // Backtracking
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> v;

        combination(ans, v, candidates, target, 0);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans =
        obj.combinationSum(candidates, target);

    cout << "Combinations are:\n";

    for (auto &vec : ans) {
        cout << "[ ";
        for (auto &num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}