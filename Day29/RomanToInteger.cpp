#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int curr = mpp[s[i]];

            if (i + 1 < n && curr < mpp[s[i + 1]]) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    string s = "MCMXCIV";

    cout << "Roman   : " << s << endl;
    cout << "Integer : " << obj.romanToInt(s) << endl;

    return 0;
}