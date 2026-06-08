#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;

    for(int i =0;i<n;i++){
        int x;
        cout<<"Enter the elements of the vector : ";
        cin>>x;
        a.push_back(x);
    }

    for(int i=0;i<n;i++){
        cout<< a[i]<<" "<<endl;
    }

    int k = 6;
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        xr = xr ^ a[i];
        // looking for k
        int f = xr ^ k;
        cnt += mpp[f];
        mpp[xr]++;
    }
    cout<<cnt;
}