
/************************************************************ C++ ************************************************/

class Solution {
  public:
        int dfs(int u, int dest, vector<vector<int> >& adj, vector<int>& dp) {
        // Base Case: If current node is destination, count as 1 path
        if (u == dest) {
            return 1;
        }

        // If result already computed for u, return it
        if (dp[u] != -1) {
            return dp[u];
        }

        int count = 0;

        // Explore all neighbors of current node u
        for (int v : adj[u]) {
            count += dfs(v, dest, adj, dp);  // Recursive call to child node v
        }

        // Store result in dp array before returning
        return dp[u] = count;  // Total paths from u to dest
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int> > adj(V);  // Adjacency list

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);  // Directed edge u -> v
        }

        // Step 2: Initialize dp array with -1 to represent uncomputed states
        vector<int> dp(1001, -1);

        // Step 3: Start DFS from source to destination
        return dfs(src, dest, adj, dp);
        
    }
};
