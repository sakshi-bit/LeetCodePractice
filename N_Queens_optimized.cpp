class Solution {
public:
    /*
    Time Complexity: O(N!)  
    -----------------------
    - For each column, we try N rows but prune invalid choices quickly.
    - In total, we explore all valid permutations → O(N!)

    Space Complexity: O(N^2) + O(3N - 2)
    -----------------------------------
    - O(N^2) for the board
    - O(N) for left_row
    - O(2N - 1) for upper_diagonal and lower_diagonal
    - O(N) recursion stack depth
    - Output space = O(number of solutions * N^2)
    */

    // Optimized backtracking with constant-time safety checks
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& left_row, vector<int>& upper_diagonal, vector<int>& lower_diagonal, int n) {
        // Base case: all columns are filled
        if(col == n) {
            ans.push_back(board); // valid solution found
            return;
        }

        for(int row = 0; row < n; row++) {
            // Check if placing a queen at (row, col) is safe
            if(left_row[row] == 0 && 
               lower_diagonal[row + col] == 0 && 
               upper_diagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';
                left_row[row] = 1;
                lower_diagonal[row + col] = 1;
                upper_diagonal[n - 1 + col - row] = 1;

                // Recurse for next column
                solve(col + 1, board, ans, left_row, upper_diagonal, lower_diagonal, n);

                // Backtrack: remove the queen
                board[row][col] = '.';
                left_row[row] = 0;
                lower_diagonal[row + col] = 0;
                upper_diagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Main function to start solving N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;      // to store all solutions
        vector<string> board(n, string(n, '.')); // initialize empty board

        // Hashing arrays to track threats
        vector<int> left_row(n, 0);
        vector<int> upper_diagonal(2 * n - 1, 0);
        vector<int> lower_diagonal(2 * n - 1, 0);

        // Begin recursion from column 0
        solve(0, board, ans, left_row, upper_diagonal, lower_diagonal, n);

        return ans;
    }
};
