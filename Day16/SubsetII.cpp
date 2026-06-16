#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& ans,
                vector<vector<int>>& finalAns,
                int idx, bool flag) {

        if (idx == nums.size()) {
            finalAns.push_back(ans);
            return;
        }

        if (flag == true) {
            ans.push_back(nums[idx]);
            helper(nums, ans, finalAns, idx + 1, true);
            ans.pop_back();
        }

        if (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            helper(nums, ans, finalAns, idx + 1, false);
        } else {
            helper(nums, ans, finalAns, idx + 1, true);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> finalAns;
        vector<int> ans;

        helper(nums, ans, finalAns, 0, true);

        return finalAns;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Subsets are:\n";

    for (auto subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}