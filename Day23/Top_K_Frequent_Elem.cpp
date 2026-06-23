#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int ele : nums) {
            mp[ele]++;
        }

        // Min Heap: {frequency, element}
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (auto x : mp) {
            int ele = x.first;
            int freq = x.second;

            pq.push({freq, ele});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}