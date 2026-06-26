#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long min;

    MinStack() {
        min = LLONG_MAX;
    }

    void push(int val) {
        long long x = val;
        if(st.empty()) {
            st.push(x);
            min = x;
        }
        else if(x >= min) {
            st.push(x);
        }
        else {
            st.push(2 * x - min);
            min = x;
        }
    }

    void pop() {
        if(st.top() < min) {
            min = 2 * min - st.top();
        }
        st.pop();
    }

    int top() {
        if(st.top() < min)
            return (int)min;
        return (int)st.top();
    }

    int getMin() {
        return (int)min;
    }
};

int main() {
    MinStack minStack;   // ["MinStack"]

    minStack.push(-2);   // ["push",-2]
    minStack.push(0);    // ["push",0]
    minStack.push(-3);   // ["push",-3]

    cout << minStack.getMin() << endl; // ["getMin"] -> -3

    minStack.pop();                  // ["pop"]

    cout << minStack.top() << endl;     // ["top"] -> 0
    cout << minStack.getMin() << endl;  // ["getMin"] -> -2

    return 0;
}