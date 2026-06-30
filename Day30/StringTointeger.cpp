#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;

        int i = 0;

        // Remove leading spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        s = s.substr(i);

        if (s.length() == 0) return 0;

        int sign = +1;
        long ans = 0;

        if (s[0] == '-')
            sign = -1;

        int maxi = INT_MAX;
        int mini = INT_MIN;

        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while (i < s.length()) {

            if (!isdigit(s[i]))
                break;

            ans = ans * 10 + (s[i] - '0');

            if (sign == -1 && -1 * ans < mini)
                return mini;

            if (sign == 1 && ans > maxi)
                return maxi;

            i++;
        }

        return (int)(sign * ans);
    }
};

int main() {
    Solution obj;

    string s = "   -42";
    cout << "Output: " << obj.myAtoi(s) << endl;

    return 0;
}