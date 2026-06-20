#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int nth;
    cout << "Enter the root : ";
    cin >> nth;

    int low = 1;
    int high = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        long long val = pow(mid, nth);

        if(val == n) {
            cout << "The " << nth << "th root of " << n << " is : " << mid;
            break;
        }
        else if(val < n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}