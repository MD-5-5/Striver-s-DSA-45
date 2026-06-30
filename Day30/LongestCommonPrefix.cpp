#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if (n == 1)
            return strs[0];

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[n - 1];

        string ans = "";

        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] == last[i])
                ans += first[i];
            else
                return ans;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };

    cout << "Longest Common Prefix = " << obj.longestCommonPrefix(strs) << endl;

    return 0;
}