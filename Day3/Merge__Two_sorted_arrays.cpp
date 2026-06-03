#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,0,0,0};
    int m = 3;

    int brr[] = {2,5,6};


    int n = 3;

    int i = m-1;

    int j = n-1;
    int k = m+n-1;

    while(i>=0 && j>=0){
        if(arr[i]>brr[j]){
            arr[k--] = arr[i--];
        }
        else arr[k--] = brr[j--];
    }
    while(j>=0){
        arr[k--] = brr[j--];
    }
    for(int i=0;i<m+n;i++){
        cout<<arr[i]<<" ";
    }
}