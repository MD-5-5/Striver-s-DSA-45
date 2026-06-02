#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int kadane(vector<int>& arr){
    int n = arr.size();
    ll sum = 0;
    ll maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}
int main(){
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadane(arr);
}