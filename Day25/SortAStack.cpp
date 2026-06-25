#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    sortedInsert(st, x);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if (st.empty())
        return;

    int temp = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, temp);
}

int main() {
    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}