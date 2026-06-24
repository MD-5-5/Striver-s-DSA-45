#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    void push(int x) {
        q.push(x);

        int n = q.size();

        // Rotate previous elements
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Top: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    cout << "Top: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    return 0;
}
