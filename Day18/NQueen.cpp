#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CanPlace(int row, int col, vector<string> board, int n) {
        int duprow = row;
        int dupcol = col;

        // Upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        // Left side
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        row = duprow;
        col = dupcol;

        // Lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board,
               vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (CanPlace(row, col, board, n)) {
                board[row][col] = 'Q';

                solve(col + 1, board, ans, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);

    cout << "\nTotal Solutions: " << ans.size() << "\n\n";

    for (int k = 0; k < ans.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";

        for (auto row : ans[k]) {
            cout << row << endl;
        }

        cout << endl;
    }

    return 0;
}