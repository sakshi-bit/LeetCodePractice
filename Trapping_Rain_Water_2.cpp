class Solution {
public:
    typedef vector<int> V; // {height, row, col}
    vector<vector<int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // 4 directions: down, left, right, up

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();      // number of rows
        int m = heightMap[0].size();   // number of columns

        // Min-heap (priority queue) to always process the smallest boundary height first
        priority_queue<V, vector<V>, greater<V>> boundarycells;

        // Visited matrix to mark processed cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Add left and right boundaries
        for (int row = 0; row < n; row++) {
            for (int col : {0, m - 1}) {
                boundarycells.push({heightMap[row][col], row, col});
                visited[row][col] = true;
            }
        }

        // Add top and bottom boundaries
        for (int col = 0; col < m; col++) {
            for (int row : {0, n - 1}) {
                boundarycells.push({heightMap[row][col], row, col});
                visited[row][col] = true;
            }
        }

        int trappedwater = 0;

        // Process cells using BFS + MinHeap
        while (!boundarycells.empty()) {
            V vec = boundarycells.top();
            boundarycells.pop();

            int height = vec[0];
            int i = vec[1];
            int j = vec[2];

            // Explore 4-directional neighbors
            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check bounds and if not visited
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
                    !visited[i_][j_]) {

                    // Water trapped = difference between current boundary height and neighbor height
                    trappedwater += max(0, height - heightMap[i_][j_]);

                    // Push neighbor into heap with updated height
                    boundarycells.push({max(height, heightMap[i_][j_]), i_, j_});
                    visited[i_][j_] = true;
                }
            }
        }

        return trappedwater;
    }
};

/*
Time Complexity:
- Inserting all cells into the priority queue: O(m * n * log(m * n))
- Each cell is pushed and popped once → O(m * n * log(m * n))
=> Overall: O(m * n * log(m * n))

Space Complexity:
- visited matrix: O(m * n)
- priority queue: O(m * n) in worst case
=> Overall: O(m * n)
*/
