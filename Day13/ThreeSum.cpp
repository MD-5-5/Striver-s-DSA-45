#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {

        if (nums[i] > 0)
            break;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                result.push_back(
                    {nums[i], nums[left], nums[right]}
                );

                left++;
                right--;

                while (left < right &&
                       nums[left] == nums[left - 1])
                    left++;

                while (left < right &&
                       nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    cout << "Triplets are:\n";

    for (auto triplet : ans) {

        cout << "[ ";

        for (auto x : triplet) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}