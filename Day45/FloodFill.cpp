#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int rows = image.size();
    int cols = image[0].size();
    int originalColor = image[sr][sc];
    if (originalColor == color)
        return image;

    const int directions[5] = {-1, 0, 1, 0, -1};

    auto dfs = [&](auto&& dfs, int row, int col) -> void {
        image[row][col] = color;

        for (int k = 0; k < 4; k++) {
            int nextRow = row + directions[k];
            int nextCol = col + directions[k + 1];

            if (nextRow >= 0 && nextRow < rows &&
                nextCol >= 0 && nextCol < cols &&
                image[nextRow][nextCol] == originalColor) {

                dfs(dfs, nextRow, nextCol);
            }
        }
    };
    dfs(dfs, sr, sc);
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    cout << "Flood Filled Image: ";
    for (auto &row : ans) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}