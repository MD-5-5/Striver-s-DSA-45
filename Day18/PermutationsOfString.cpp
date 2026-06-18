#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Reccurence(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);

            Reccurence(index + 1, nums, ans);

            // Backtrack
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Reccurence(0, nums, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.permute(nums);

    cout << "\nPermutations:\n";

    for (auto& perm : ans) {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}