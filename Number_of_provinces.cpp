class Solution {
public:
    /*
        DFS function
        Time Complexity: O(N + E)
        Space Complexity: O(N)  -> recursion stack in worst case
    */
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjList) {
        // Mark current node as visited
        vis[node] = 1;

        // Visit all adjacent nodes
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjList);
            }
        }
    }

    /*
        Main function
        Time Complexity:
            - Building adjacency list: O(N^2)
            - DFS traversal: O(N + E)
            - Overall: O(N^2)

        Space Complexity:
            - Adjacency list: O(N^2) (worst case, fully connected graph)
            - Visited array: O(N)
            - Recursion stack: O(N)
            - Overall: O(N^2)
    */
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Adjacency list representation of the graph
        vector<vector<int>> adjList(n);

        // Convert adjacency matrix to adjacency list
        // Time Complexity: O(N^2)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Visited array
        vector<int> vis(n, 0);

        int cnt = 0; // Number of provinces

        // DFS on each unvisited node
        // Time Complexity: O(N + E)
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;               // New connected component found
                dfs(i, vis, adjList);
            }
        }

        return cnt;
    }
};
