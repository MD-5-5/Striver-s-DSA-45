#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ngi(n);
        stack<int> st;

        ngi[n - 1] = n;
        st.push(n - 1);

        for(int i = n - 2; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(st.empty())
                ngi[i] = n;
            else
                ngi[i] = st.top();

            st.push(i);
        }

        vector<int> ans;
        int j = 0;

        for(int i = 0; i <= n - k; i++) {
            if(j < i)
                j = i;

            int mx = nums[j];

            while(j < i + k) {
                mx = nums[j];

                if(ngi[j] >= i + k)
                    break;

                j = ngi[j];
            }

            ans.push_back(mx);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums, k);

    for(int x : ans)
        cout << x << " ";

    return 0;
}