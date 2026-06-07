#include<bits/stdc++.h>
using namespace std;
vector<int>twosum(vector<int>& nums,int target){
    int n = nums.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 13;
    vector<int> ans = twosum(nums,target);

    cout<<ans[0]<<" "<<ans[1];
}