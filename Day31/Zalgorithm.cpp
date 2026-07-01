#include<bits/stdc++.h>
using namespace std;
vector<int> zMatch(string s){
    vector<int> z(s.size(),0);
    int left = 0;
    int right = 0;
    for(int i=1;i<s.size();i++){
        if(i < right){
            z[i] = z[i-left];
            if(i + z[i] > right){
                z[i] = right - i;
            }
        }
        while(i + z[i] < s.size() && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i + z[i] > right){
            left = i;
            right = i + z[i];
        }
    }
    return z;
}
int main(){
    vector<int> z = zMatch("aba$ababbababaaa");
    for(auto it : z){
        cout<< it <<" "<<endl;
    }
    return 0;
}