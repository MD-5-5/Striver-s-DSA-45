#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1,2,4,5,2};
    //Brute Force//

    // int n = nums.size();
    // map<int,int>mpp;
    // for(int i=0;i<n;i++){
    //     mpp[nums[i]]++;
    // }
    // int repeating = -1, missing = -1;
    // for(int i=1;i<=n;i++){
    //     if(mpp[i]==2) repeating = i;
    //     else if(mpp[i]==0) missing = i;
    //     if(repeating !=-1 && missing != -1){
    //         break;
    //     }
    // }
    // cout<<repeating<<" "<<missing<<endl;





    //Maths Solution ==> Solving simultaneous Eqn

    // long long n = nums.size();
    // long long Sn = (n*(n+1))/2;
    // long long sqn = (n*(n+1)*(2*n+1))/6;
    // long long S =0, S2 = 0;

    // for(int i=0;i<n;i++){
    //     S += nums[i];
    //     S2 += (long long)nums[i]*(long long)nums[i];
    // }
    // long long val1 = S - Sn; //X-Y
    // long long val2 = S2 - sqn;
    // val2 = val2/val1; //X+Y
    // long long X = (val1+val2)/2;
    // long long Y = X - val1;
    // cout<<"Repeating number is : "<<(int)X<<" "<<endl<<"Missing number is : "<<(int)Y;




    //XOR Method
    //  Even number of same number on XOR gives you = 0
    //  nums[i] ^ (1...2n)
    //  find the diffrence in number and find the first one from the right
    //  put them into two parts -> 0 or 1
    //  XOR Kerdo
    long long n = nums.size();
    int xr = 0;
    for(int i=0;i<n;i++){
        xr = xr ^ nums[i];
        xr = xr ^ (i+1);
    }
    int bitNo = 0;
    while(1){
        if((xr & (1<<bitNo)) != 0){
            break;
        }
        bitNo++;
    }
    int zero = 0;
    int one = 0;
    for(int i=0;i<n;i++){
        // 1 gang
        if((nums[i] & (1<<bitNo)) != 0){
            one = one ^ nums[i];
        }
        // 0 gang
        else{
            zero = zero ^ nums[i];
        }
    }


    for(int i=1;i<=n;i++){
        // 1 gang
        if((i & (1<<bitNo)) != 0){
            one = one ^ i;
        }
        // 0 gang
        else{
            zero = zero ^ i;
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i] == zero )count++;
    }
    if(count == 2){
    cout<<zero<<" "<<one;
    } 
    else{
    cout<<one<<" "<<zero;
    }
}