#include<bits/stdc++.h>
using namespace std;
bool canWePlace(int arr[], int mid, int cows, int n){
    int cntCows = 1, last = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] - last >= mid){
            cntCows++;
            last = arr[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}
int AggCows(int arr[], int cows, int n){
    sort(arr,arr+n);
    int low = 1;
    int ans = -1;
    int high = arr[n-1] - arr[0];
    while(low<=high){
        int mid = (low+high)>>1;
        if(canWePlace(arr,mid,cows,n) == true){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return high;
}
int main(){
    int arr[]= {0,3,4,7,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cows = 4;
    cout<<AggCows(arr,cows,n);
}


