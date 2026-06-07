#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {5,8,3,2,1,4};
    int n = nums.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> st;

    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    } //O(n)

    for(auto it: st){
        if(st.find(it-1) == st.end()){ //Are you the first element 
            int count = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                x = x + 1;
                count = count +1;
            }
            longest = max(longest,count);
        }
    }
    cout<<longest;
}

// TC => O(3N) ..2N + N
// SC => O(N)