#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            vector<int>& last = res.back();
            vector<int>& curr = intervals[i];

            if(curr[0]<=last[1]){
                last[1] = max(last[1],curr[1]);
            }
            else res.push_back(curr);
        }
        for(int i=0;i<res.size();i++){
            cout<<res[i][0]<<" "<<res[i][1]<<endl;
        }
    }