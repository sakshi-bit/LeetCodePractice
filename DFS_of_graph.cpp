class Solution {
  private:
    // Recursive DFS function
    void dfs(int node, vector<vector<int>>& adj, int vis[], vector<int>& ls) {

        vis[node] = 1;          // mark node as visited
        ls.push_back(node);     // add to DFS traversal result

        // traverse all its neighbours
        for (auto it : adj[node]) {
            if (!vis[it]) {     // if neighbour not visited
                dfs(it, adj, vis, ls);  // recurse
            }
        }
    }

  public:
    vector<int> dfs(vector<vector<int>>& adj) {

        int V = adj.size();     // total number of nodes
        int vis[V] = {0};       // visited array initialized to 0
        vector<int> ls;         // stores DFS traversal result

        int start = 0;          // start DFS from node 0
        dfs(start, adj, vis, ls);

        return ls;
    }
};
