#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numberRows){
    vector<vector<int>> v;
    for(int i=1;i<=numberRows;i++){
        vector<int> a(i,1);
        v.push_back(a);
    }
    for(int i=1;i< numberRows;i++){
        for(int j=1;j<i;j++){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v;
}
int main(){

    int numberRows = 5;
    vector<vector<int>> ans = generate(numberRows);
    for(auto &row : ans){
        for(int x : row){
            cout << x << " ";
        }
        cout << endl;
    }
}
