#include<bits/stdc++.h>
using namespace std;
vector<int> MajorityElemII(vector<int>& nums, int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    vector<int> ans;
    for(auto it : mpp){
        if(it.second > n/3){
            ans.push_back(it.first);
        }
    }
    return ans;
}
int main(){
    vector<int>nums = {3,2,3};
    int n = nums.size();
    vector<int> result = MajorityElemII(nums,n);
    for(int x : result) {
        cout<<x<<" ";
    }
    return 0;
}