#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];

        int counternew = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1)
                    counternew++;
            }
        }

        int time = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int count = 0;

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time,t);

            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 2 &&
                   grid[nrow][ncol] == 1) {

                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        if(count != counternew)
            return -1;

        return time;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution obj;
    cout << obj.orangesRotting(grid);

    return 0;
}