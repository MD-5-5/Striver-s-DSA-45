#include <iostream>
using namespace std;

class Stack {
public:
    int arr[5];
    int topIdx;

    Stack() {
        topIdx = -1;
    }

    void push(int val) {
        if (topIdx == 4) {
            cout << "Stack is Full!" << endl;
            return;
        }

        topIdx++;
        arr[topIdx] = val;
    }

    int pop() {
        if (topIdx == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        int x = arr[topIdx];
        topIdx--;
        return x;
    }

    int top() {
        if (topIdx == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        return arr[topIdx];
    }

    int size() {
        return topIdx + 1;
    }

    bool empty() {
        return topIdx == -1;
    }

    void display() {
        for (int i = 0; i <= topIdx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Stack Elements: ";
    st.display();

    cout << "Top Element: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "After Pop: ";
    st.display();

    return 0;
}