#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);         // columns
        vector<bool> diag1(2 * n - 1, false); // main diagonal row - col
        vector<bool> diag2(2 * n - 1, false); // anti-diagonal row + col
        backtrack(0, n, board, col, diag1, diag2, res);
        return res;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            // Place queen
            board[row][c] = 'Q';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

            backtrack(row + 1, n, board, col, diag1, diag2, res);

            // Backtrack
            board[row][c] = '.';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }
};


int main() {
    Solution s;
    auto res = s.solveNQueens(4);
    for (auto& board : res) {
        for (string& row : board) {
            printf("%s\n", row.c_str());
        }
        printf("\n");
    }
}
