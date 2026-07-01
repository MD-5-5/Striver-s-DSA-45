#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> LPS(string pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int strStr(string haystack, string needle) {

        if (needle.empty())
            return 0;

        vector<int> lps = LPS(needle);

        int i = 0;
        int j = 0;

        while (i < haystack.size()) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j;
            }
            else if (i < haystack.size() && haystack[i] != needle[j]) {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    string haystack = "butsadsad";
    string needle = "sad";

    int ans = obj.strStr(haystack, needle);

    cout << "First Occurrence Index = " << ans << endl;

    return 0;
}