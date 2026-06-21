#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countStudents(vector<int> &arr, int pages) {
        int students = 1;
        long long pagesStudent = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                students++;
                pagesStudent = arr[i];
            }
        }

        return students;
    }

    int findPages(vector<int>& arr, int n, int m) {

        // If students are more than books
        if (m > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int students = countStudents(arr, mid);

            if (students > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {

    vector<int> arr = {25, 46, 28, 49, 24};
    int n = arr.size();
    int m = 4;

    Solution obj;

    int ans = obj.findPages(arr, n, m);

    cout << "The answer is: " << ans << endl;

    return 0;
}