#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int i = 0;
    for(int j=0;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i] = nums[j];
        }
    }
    cout<<i+1;
}