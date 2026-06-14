#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1,1,0,1,1,1};
    int count = 0;
    int maxCount = 0;
    for(int num : nums){
        if(num==1){
            count++;
            maxCount = max(maxCount,count);
        }
        else {
            count = 0;
        }
    }
    cout<<maxCount;
}