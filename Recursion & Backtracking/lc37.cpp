#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
bool canPlace(vector<vector<char>> board, char n, int row, int col) {
    for (auto c : board[row]) if (c == n) return false;
    int effCol;
    int effRow;
    if (col < 3) effCol = 0;
    else if (col < 6) effCol = 3;
    else effCol = 6;
    if (row < 3) effRow = 0;
    else if (row < 6) effRow = 3;
    else effRow = 6;
    for (int i = effRow; i < effRow + 3; i++) for (int j = effCol; j < effCol + 3; j++) if (board[i][j] == n) return false;
    for (int i = 0; i < 9; i++) if (board[i][col] == n) return false;
    return true;
}
bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (canPlace(board, c, i, j)) {
                        board[i][j] = c;
                        if (solve(board)) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) { solve(board); }
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << board[i][j] << ' ';
        cout << endl;
    }
    return 0;
}