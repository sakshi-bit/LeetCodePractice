class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {

        int n = adj.size();

        // visited array to track which nodes are already processed
        // SC: O(n)
        vector<int> vis(n, 0);

        // BFS queue
        // SC: O(n) in worst case (all nodes in queue)
        queue<int> q;

        // start BFS from node 0
        vis[0] = 1;
        q.push(0);

        vector<int> bfs;  // stores BFS traversal order

        // BFS Loop
        // TC: O(n + m) where n = nodes, m = edges
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            bfs.push_back(node);

            // traverse all neighbours
            for (int it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;     // mark visited
                    q.push(it);      // push neighbour to queue
                }
            }
        }

        return bfs;
    }
};
