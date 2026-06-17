#include <bits/stdc++.h>
using namespace std;

class Solution {
    void findCombination(int idx, int target, vector<int>& candidates,
                         vector<vector<int>>& ans, vector<int>& v) {
        
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Duplicate elements skip karo
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Sorted array hai, isliye aage ke elements bhi bade honge
            if (candidates[i] > target)
                break;

            v.push_back(candidates[i]);

            findCombination(i + 1,
                            target - candidates[i],
                            candidates,
                            ans,
                            v);

            v.pop_back(); // Backtracking
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v;

        findCombination(0, target, candidates, ans, v);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = obj.combinationSum2(candidates, target);

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