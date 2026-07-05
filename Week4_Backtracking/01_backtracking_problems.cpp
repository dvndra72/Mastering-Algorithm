class NQueens {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false), diag1(2 * n, false), diag2(2 * n, false);
        solve(0, n, board, col, diag1, diag2, result);
        return result;
    }

private:
    void solve(int row, int n, vector<string>& board,
               vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2,
               vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n] || diag2[row + c]) continue;
            board[row][c] = 'Q';
            col[c] = diag1[row - c + n] = diag2[row + c] = true;

            solve(row + 1, n, board, col, diag1, diag2, result);

            board[row][c] = '.';
            col[c] = diag1[row - c + n] = diag2[row + c] = false;
        }
    }
};

class SudokuSolver {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;

                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve(board)) return true;
                        board[i][j] = '.';  // backtrack
                    }
                }
                return false;  
            }
        }
        return true;  
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};

class Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(nums, 0, curr, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};
