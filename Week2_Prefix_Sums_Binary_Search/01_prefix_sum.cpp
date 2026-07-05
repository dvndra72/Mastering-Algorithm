#include <bits/stdc++.h>
using namespace std;

class PrefixSum1D {
    vector<long long> prefix;
public:
    PrefixSum1D(const vector<int>& arr) {
        int n = arr.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];
    }

    long long query(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }
};

class PrefixSum2D {
    vector<vector<long long>> prefix;
public:
    PrefixSum2D(const vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        prefix.assign(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1]
                                   + prefix[i+1][j] - prefix[i][j];
    }

    long long query(int r1, int c1, int r2, int c2) {
        return prefix[r2+1][c2+1] - prefix[r1][c2+1]
               - prefix[r2+1][c1] + prefix[r1][c1];
    }
};

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    PrefixSum1D ps(arr);
    cout << "Sum of arr[2..5] = " << ps.query(2, 5) << "\n";  // 4+1+5+9 = 19

    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    PrefixSum2D ps2d(grid);
    cout << "Sum of submatrix (1,1)-(2,2) = " << ps2d.query(1, 1, 2, 2) << "\n";  // 5+6+8+9 = 28

    return 0;
}
