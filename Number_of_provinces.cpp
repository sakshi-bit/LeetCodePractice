class Solution {
public:
    // DFS function to mark all nodes in the same connected component
    void dfs(int node, vector<int>& vis, vector<vector<int>> adjList) {
        // Mark current node as visited
        vis[node] = 1;

        // Visit all adjacent nodes
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Adjacency list representation of the graph
        vector<vector<int>> adjList(n);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Visited array to keep track of visited cities
        vector<int> vis(n, 0);

        int cnt = 0; // Number of provinces

        // Traverse all nodes
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // Found a new province
                cnt++;
                dfs(i, vis, adjList);
            }
        }

        return cnt;
    }
};
