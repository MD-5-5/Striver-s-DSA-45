#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        string nstr = "";

        int freq = 1;
        char ch = str[0];

        for (int i = 1; i < str.length(); i++) {
            char dh = str[i];

            if (ch == dh) {
                freq++;
            } else {
                nstr += (to_string(freq) + ch);
                freq = 1;
                ch = dh;
            }
        }

        nstr += (to_string(freq) + ch);

        return nstr;
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << obj.countAndSay(n) << endl;

    return 0;
}