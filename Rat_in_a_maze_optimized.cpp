class Solution {
public:
    /**
     * @brief Helper function to explore all paths from (i, j) to (n-1, n-1)
     * 
     * @param i      Current row
     * @param j      Current column
     * @param maze   The maze grid
     * @param ans    Stores all valid path strings
     * @param vis    Visited matrix to prevent revisiting
     * @param di     Row direction offsets (D, L, R, U)
     * @param dj     Column direction offsets
     * @param path   Current path string (e.g., "DRRD")
     * @param n      Size of maze (n x n)
     */
    void solve(int i, int j, vector<vector<int>>& maze, vector<string>& ans,
               vector<vector<int>>& vis, int di[], int dj[], string path, int n) {

        // Base Case: Reached destination
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // Direction order: D, L, R, U
        string dir = "DLRU";

        // Try all 4 directions
        for (int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];

            // Valid move check: within bounds, not visited, and path is open (1)
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && maze[nexti][nextj] == 1) {

                vis[nexti][nextj] = 1;
                solve(nexti, nextj, maze, ans, vis, di, dj, path + dir[index], n);
                vis[nexti][nextj] = 0; // Backtrack
            }
        }
    }

    /**
     * @brief Main function to find all valid paths in the maze from (0,0) to (n-1,n-1)
     * 
     * @param maze  Input grid where 1 is open and 0 is blocked
     * @return vector<string> containing all valid paths
     */
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Directions: D, L, R, U
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        // Only start if the starting cell is open
        if (maze[0][0] == 1) {
            vis[0][0] = 1;
            solve(0, 0, maze, ans, vis, di, dj, "", n);
        }

        return ans;
    }
};
