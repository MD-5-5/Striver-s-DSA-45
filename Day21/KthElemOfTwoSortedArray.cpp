#include<bits/stdc++.h>
using namespace std;
int kthElem(vector<int>& one,vector<int>& two, int n, int m, int k){
    if(n>m){
        return kthElem(one,two,n,m,k);
    }   
    int low = max(0,k-m), high = min(k,n);
    while(low<=high){
        int cut1 = (low+high) >> 1;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : one[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : two[cut2-1];
        int r1 = cut1 == n ? INT_MAX : one[cut1];
        int r2 = cut2 == m ? INT_MAX : two[cut2];

        if(l1 <= r2 && l2 <= r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high = cut1-1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return 1;
}
int main(){
    vector<int>one = {7,12,14,15};
    int n = 4;
    vector<int>two = {1,2,3,4,9,11};
    int m = 6;
    int k = 4;
    cout<<kthElem(one,two,n,m,k);
}