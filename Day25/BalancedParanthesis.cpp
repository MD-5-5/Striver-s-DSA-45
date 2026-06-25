#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;

                char ch = st.top();
                st.pop();

                if ((s[i] == ')' && ch == '(') ||
                    (s[i] == ']' && ch == '[') ||
                    (s[i] == '}' && ch == '{')) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution obj;
    string s;
    cout << "Enter the string: ";
    cin >> s;

    if (obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}