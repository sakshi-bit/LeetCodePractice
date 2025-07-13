#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Helper function to explore all paths from current cell (i, j)
 * 
 * @param i     Current row index
 * @param j     Current column index
 * @param arr   Input grid representing the maze
 * @param n     Size of the maze (n x n)
 * @param ans   Stores all valid paths from (0, 0) to (n-1, n-1)
 * @param vis   Visited matrix to avoid cycles
 * @param path  Current path string (e.g., "DRDD")
 */
void solve(int i, int j, vector<vector<int>>& arr, int n, vector<string>& ans,
           vector<vector<int>>& vis, string path) {

    // Base Case: Reached destination
    if (i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    // Move Down
    if (i + 1 < n && !vis[i + 1][j] && arr[i + 1][j] == 1) {
        vis[i + 1][j] = 1;
        solve(i + 1, j, arr, n, ans, vis, path + 'D');
        vis[i + 1][j] = 0; // Backtrack
    }

    // Move Left
    if (j - 1 >= 0 && !vis[i][j - 1] && arr[i][j - 1] == 1) {
        vis[i][j - 1] = 1;
        solve(i, j - 1, arr, n, ans, vis, path + 'L');
        vis[i][j - 1] = 0; // Backtrack
    }

    // Move Right
    if (j + 1 < n && !vis[i][j + 1] && arr[i][j + 1] == 1) {
        vis[i][j + 1] = 1;
        solve(i, j + 1, arr, n, ans, vis, path + 'R');
        vis[i][j + 1] = 0; // Backtrack
    }

    // Move Up
    if (i - 1 >= 0 && !vis[i - 1][j] && arr[i - 1][j] == 1) {
        vis[i - 1][j] = 1;
        solve(i - 1, j, arr, n, ans, vis, path + 'U');
        vis[i - 1][j] = 0; // Backtrack
    }
}

/**
 * @brief Main function to find all paths in a maze
 * 
 * @param arr   n x n grid where 1 = open path, 0 = blocked
 * @param n     Size of the grid
 * @return vector<string> All valid paths from top-left to bottom-right
 * 
 * @note Assumes start (0,0) and end (n-1,n-1) are 1
 */
vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (arr[0][0] == 1) {
        vis[0][0] = 1; // Mark start as visited
        solve(0, 0, arr, n, ans, vis, "");
    }

    // Optional: sort result if required
    // sort(ans.begin(), ans.end());

    return ans;
}

/**
 * ✅ Time Complexity:
 *    - Worst case: O(4^(n^2))
 *    - Because each cell can potentially move in 4 directions
 *    - Exponential due to exploring all possible paths
 * 
 * ✅ Space Complexity:
 *    - O(n^2) for the visited matrix
 *    - O(2n) max call stack in recursion for each path
 *    - O(P * 2n) to store all valid paths (P = number of valid paths)
 */

