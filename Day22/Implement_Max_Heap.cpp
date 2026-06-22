#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    // Insert kerna heap mei peeche se
    void insert(int val) {
        heap.push_back(val);

        int idx = heap.size() - 1;

        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (heap[parent] < heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            }
            else {
                break;
            }
        }
    }

    // Delete Root
    void deleteRoot() {
        int n = heap.size();

        if (n == 0) return;

        heap[0] = heap[n - 1];
        heap.pop_back();

        int idx = 0;

        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < heap.size() &&
                heap[left] > heap[largest])
                largest = left;

            if (right < heap.size() &&
                heap[right] > heap[largest])
                largest = right;

            if (largest == idx)
                break;

            swap(heap[idx], heap[largest]);
            idx = largest;
        }
    }

    // Get Maximum Element
    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    // Print Heap
    void print() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {

    MaxHeap h;
    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(20);
    h.insert(40);

    cout << "Heap: ";
    h.print();

    cout << "Max Element: " << h.top() << endl;

    h.deleteRoot();

    cout << "After Deletion: ";
    h.print();
}