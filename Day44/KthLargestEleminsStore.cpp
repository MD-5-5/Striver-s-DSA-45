#include<bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            pq.push(x);

            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};

int main() {

    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest obj(k, nums);

    cout << "add(3) " << obj.add(3) << endl;
    cout << "add(5) " << obj.add(5) << endl;
    cout << "add(10)" << obj.add(10) << endl;
    cout << "add(9) " << obj.add(9) << endl;
    cout << "add(4) " << obj.add(4) << endl;

    return 0;
}