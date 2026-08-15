class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }

private:
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[node]) return 0;
        visited[node] = true;

        for(int next : adj[node]) dfs(next, adj, visited);
        return 0;
    }
};
