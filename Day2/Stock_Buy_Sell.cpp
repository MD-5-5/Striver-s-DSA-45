#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>prices = {7,1,5,3,6,4};
    int mini = prices[0];
    int maxi = 0;
    for(int i=0;i<prices.size();i++){
        int cost = prices[i] - mini;
        maxi = max(maxi,cost);
        mini = min(mini,prices[i]);
    }
    cout<<maxi;
}