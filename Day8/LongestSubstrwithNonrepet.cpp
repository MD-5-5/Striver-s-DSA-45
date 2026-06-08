#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }
        st.insert(s[right]);

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}