#include<bits/stdc++.h>
using namespace std;
bool isPresent(vector<vector<int>>& matrix,int target){
    if(!matrix.size()) return false;
    int row = matrix.size();
    int col = matrix[0].size();
    int low = 0, high = (row*col)-1;
    while(low<=high){
        int mid = (low+high)>>1;
        if(matrix[mid/col][mid%col] == target) return true;

        if(matrix[mid/col][mid%col]<target){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
        return false;
    };
}
int main(){
    vector<vector<int>> matrix{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    }; //values will be from idx(1-11);
    int target = 11;
    cout<<isPresent(matrix,target);
}

// TC = > O(n*m)
// SC = > O(1)