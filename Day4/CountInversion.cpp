#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        int inversionCount = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right]);
                inversionCount += (mid - left + 1);
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];

            return inversionCount;
        }

    // Recursive merge sort function
    int mergeSort(vector<int>& arr, int low, int high) {
        int inversionCount = 0;
        if (low >= high)
            return inversionCount;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        inversionCount += mergeSort(arr, low, mid);

        // Recursively sort right half
        inversionCount += mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        inversionCount += merge(arr, low, mid, high);
        return inversionCount;
    }
int main(){
    vector<int>arr = {5,3,2,1,4};
    int n = arr.size();
    cout<<mergeSort(arr,0,n-1);
}