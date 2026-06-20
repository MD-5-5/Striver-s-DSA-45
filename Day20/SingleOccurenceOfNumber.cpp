#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (mid % 2 == 1)
            mid--;

        if (nums[mid] == nums[mid + 1]) {
            // Single element right side mein hai
            low = mid + 2;
        }
        else {
            // Single element left side mein hai
            high = mid;
        }
    }

    return nums[low];
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Single non-duplicate element is: " << singleNonDuplicate(nums);

    return 0;
}