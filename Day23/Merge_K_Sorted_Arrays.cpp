#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr) {

        vector<int> res;

        // {value, row, col}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>> pq;

        int k = arr.size();

        // first element of every array
        for(int i = 0; i < k; i++) {
            if(!arr[i].empty()) {
                pq.push({arr[i][0], i, 0});
            }
        }

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();
            int val = curr[0];
            int row = curr[1];
            int col = curr[2];

            res.push_back(val);

            // next element usi Array ka 
            if(col + 1 < arr[row].size()) {
                pq.push({arr[row][col + 1], row, col + 1});
            }
        }

        return res;
    }
};

int main() {

    vector<vector<int>> arr = {
        {1,4,5},
        {1,3,4},
        {2,6}
    };

    Solution obj;

    vector<int> res = obj.mergeKSortedArrays(arr);

    for(int x : res)
        cout << x << " ";

    return 0;
}