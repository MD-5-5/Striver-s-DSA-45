#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> left; // Max Heap
    priority_queue<int, vector<int>, greater<int>> right; // Min Heap

    void addNum(int num) {
        if (left.empty() || num < left.top())
            left.push(num);
        else
            right.push(num);
        // Balance heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }
    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }

        return (left.size() > right.size()) ? left.top() : right.top();
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl;

    return 0;
}