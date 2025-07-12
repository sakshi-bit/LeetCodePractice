class Solution {
public:
    /*
    Time Complexity: O(9^(n * n))
    -----------------------------------
    - For each empty cell, we try digits 1 to 9 → up to 9 choices per cell.
    - So worst-case time is exponential: O(9^k), where k = number of empty cells.

    Space Complexity: O(1) (ignoring recursion stack)
    -----------------------------------
    - The board is modified in-place.
    - Max recursion depth = number of empty cells, so O(k) auxiliary stack space.
    */

    // Check whether placing 'ch' at board[row][col] is valid
    bool isValid(int row, int col, char ch, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            // Check column
            if(board[i][col] == ch) return false;

            // Check row
            if(board[row][i] == ch) return false;

            // Check 3x3 subgrid
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    // Recursive backtracking function to solve Sudoku
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    // Try placing digits '1' to '9'
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(i, j, ch, board)) {
                            board[i][j] = ch;           // place the digit
                            if(solve(board)) return true; // proceed recursively
                            board[i][j] = '.';           // backtrack
                        }
                    }
                    return false; // if no digit is valid, return false
                }
            }
        }
        return true; // board completely filled without conflict
    }

    // Main function to start the solving process
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
