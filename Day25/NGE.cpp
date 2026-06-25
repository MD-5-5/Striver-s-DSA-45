#include<iostream>
#include<stack>
using namespace std;
int main (){
    int arr[] = {3,1,2,5,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //using stack : pop,ans,push
   int nge[n];
   stack<int> st;
   nge[n-1] = -1;
   st.push(arr[n-1]);
   for(int i=n-2;i>=0;i--){
        //pop all the elemets smaller than arr[i]
        while(st.size()>0 && st.top()<=arr[i]){
            st.pop();
        }
        if(st.size()==0) nge[i] = -1;
        else nge[i] = st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    cout<<endl;
}

//T.C = O(n)  
//S.C = O(n)