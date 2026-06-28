#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    int top = 0;
    int down = mat.size() - 1;

    // Find potential celebrity
    while (top < down) {
        if (mat[top][down] == 1) {
            top++;
        }
        else if (mat[down][top] == 1) {
            down--;
        }
        else {
            top++;
            down--;
        }
    }

    // Verify the candidate
    for (int i = 0; i < mat.size(); i++) {
        if (i == top)
            continue;

        if (mat[top][i] == 0 && mat[i][top] == 1)
            continue;
        else
            return -1;
    }

    return top;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    cout << "Matrix:\n";
    for (auto &row : mat) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    int ans = celebrity(mat);

    if (ans == -1)
        cout << "No Celebrity Exists\n";
    else
        cout << "Celebrity is Person " << ans << endl;

    return 0;
}