#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half sorted
        if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right half sorted
        else {

            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout<<searchElement(nums, target);

    return 0;
}