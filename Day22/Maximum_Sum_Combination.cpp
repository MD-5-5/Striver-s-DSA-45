#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(vector<int>& A,
                            vector<int>& B,
                            int k)
{
    int n = A.size();

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    priority_queue<
        pair<int,pair<int,int>>
    > pq;

    set<pair<int,int>> visited;

    pq.push({A[0] + B[0], {0,0}});
    visited.insert({0,0});

    vector<int> ans;

    while(k--)
    {
        auto top = pq.top();
        pq.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        ans.push_back(sum);

        if(i + 1 < n &&
           visited.find({i+1,j}) == visited.end())
        {
            pq.push({
                A[i+1] + B[j],
                {i+1,j}
            });

            visited.insert({i+1,j});
        }

        if(j + 1 < n &&
           visited.find({i,j+1}) == visited.end())
        {
            pq.push({
                A[i] + B[j+1],
                {i,j+1}
            });

            visited.insert({i,j+1});
        }
    }

    return ans;
}

int main()
{
    vector<int> A = {7,3};
    vector<int> B = {1,6};

    int k = 2;

    vector<int> ans =
        maxCombinations(A,B,k);

    for(int x : ans)
        cout << x << " ";
}