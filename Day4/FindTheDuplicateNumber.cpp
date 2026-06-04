#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1,3,4,2,2};
    int n = nums.size();
    int i = 0;
    while(i<n){
        if(nums[i]!=i){
            int correctIndex = nums[i];
            if(nums[correctIndex] == nums[i]){
                cout<< nums[i];
                return 0;
            }
            else swap(nums[i],nums[correctIndex]); //for correct positioning
        }
        else{
            i++;
        }
    }
}