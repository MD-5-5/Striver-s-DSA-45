#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {

    unordered_set<string> st(wordDict.begin(), wordDict.end());

    int n = s.size();
    vector<bool> dp(n + 1, false);

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && st.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    string s = "takeuforward";
    vector<string> wordDict = {
        "take",
        "forward",
        "you",
        "u"
    };
    bool ans = wordBreak(s, wordDict);
    cout << (ans ? "true" : "false") << endl;
    return 0;
}