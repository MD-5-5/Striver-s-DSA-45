#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = nums.size();
    int maxiLen = 0;
    int right = 0, left = 0;

    int sum = nums[0];

    //If sum exceeds the limit k
    // Window shrink
    while(right<n){

        //Shrink the window if sum > k
        while(left<=right && sum>k){
            sum -= nums[left];
            left++;
        }

        if(sum == k){
            maxiLen = max(maxiLen, right-left+1);
        }

        //Window expand
        right++;
        if(right<n){
            sum += nums[right];
        }
    }
    cout<<"Maximum length is : "<< maxiLen;
}