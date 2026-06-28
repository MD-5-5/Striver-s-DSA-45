#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;

    StockSpanner() {
        idx = -1;
    }
    int next(int price) {
        idx++;

        while (!st.empty() && st.top().first <= price)
            st.pop();

        int ans;
        if (st.empty())
            ans = idx + 1;
        else
            ans = idx - st.top().second;

        st.push({price, idx});
        return ans;
    }
};

int main() {
    StockSpanner sp;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Prices : ";
    for (int x : prices)
        cout << x << " ";

    cout << "\nSpan   : ";
    for (int x : prices)
        cout << sp.next(x) << " ";

    cout << endl;

    return 0;
}