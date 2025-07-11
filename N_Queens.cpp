class Solution {
public:
    /*
    Time Complexity: O(N!)  
    -----------------------
    - At each column, we try placing a queen in N rows.
    - But due to constraints (no two queens attacking), we try fewer combinations as we go deeper.
    - Still, in the worst case, we try all N! permutations, so TC = O(N!)

    Space Complexity: O(N^2)
    -------------------------
    - O(N^2) to store the board.
    - O(N) recursion stack depth.
    - Output storage depends on number of solutions: each board = O(N^2), total solutions = variable.
    */

    // Check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check upper-left diagonal
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }

        // Check left side
        row = duprow; col = dupcol;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        // Check lower-left diagonal
        row = duprow; col = dupcol;
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++; col--;
        }

        return true; // Safe to place queen
    }

    // Recursive function to place queens column by column
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        // Base case: all queens placed
        if(col == n) {
            ans.push_back(board); // store one valid board
            return;
        }

        // Try placing queen in each row of this column
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';         // place queen
                solve(col + 1, board, ans, n); // recurse for next column
                board[row][col] = '.';         // backtrack
            }
        }
    }

    // Main function to return all valid arrangements
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;   // stores all solutions
        vector<string> board(n);      // one board configuration
        string s(n, '.');             // empty row

        // Initialize the board
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        // Start placing queens from column 0
        solve(0, board, ans, n);
        return ans;
    }
};
