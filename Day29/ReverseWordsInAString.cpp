#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseRange(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s) {
        int i = 0;
        int j = 0;

        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ')
                j++;

            while (j < s.size() && s[j] != ' ')
                s[i++] = s[j++];

            while (j < s.size() && s[j] == ' ')
                j++;

            if (j < s.size()) {
                s[i++] = ' ';
            }
        }

        s.resize(i);

        // Reverse entire string
        reverseRange(s, 0, s.size() - 1);

        // Reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverseRange(s, start, end - 1);
                start = end + 1;
            }
        }

        return s;
    }
};

int main() {
    Solution obj;
    string s = "  the   sky   is   blue  ";
    cout << obj.reverseWords(s) << endl;

    return 0;
}