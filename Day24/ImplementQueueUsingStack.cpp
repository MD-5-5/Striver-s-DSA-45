#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    void push(int x) {
        st.push(x);
    }

    int pop() {
        while (!st.empty()) {
            helper.push(st.top());
            st.pop();
        }

        int x = helper.top();
        helper.pop();

        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }

        return x;
    }

    int peek() {
        while (!st.empty()) {
            helper.push(st.top());
            st.pop();
        }

        int x = helper.top();

        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }

        return x;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front: " << q.peek() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    cout << "Front: " << q.peek() << endl;

    cout << "Is Queue Empty? ";
    if (q.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}