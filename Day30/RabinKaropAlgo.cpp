#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    bool rabinkarp(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        if (m > n) return false;

        const ll base = 31;
        const ll mod = 1e9 + 7;

        ll patternHash = 0;
        ll textHash = 0;
        ll power = 1;

        // base^(m-1)
        for (int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        // Initial Hash
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * base + pattern[i]) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++) {

            if (patternHash == textHash) {
                if (text.substr(i, m) == pattern)
                    return true;
            }

            if (i < n - m) {
                textHash = (textHash - text[i] * power % mod + mod) % mod;
                textHash = (textHash * base + text[i + m]) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string temp = a;

        while (temp.length() < b.length()) {
            temp += a;
            count++;
        }

        if (rabinkarp(temp, b))
            return count;

        temp += a;

        if (rabinkarp(temp, b))
            return count + 1;

        return -1;
    }
};

int main() {
    Solution obj;
    string a = "abcd";
    string b = "cdabcdab";
    cout<< obj.repeatedStringMatch(a, b) << endl;

    return 0;
}