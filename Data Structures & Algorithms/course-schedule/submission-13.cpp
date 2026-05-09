class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> k(numCourses);
        // adjacency list
        vector<vector<int>> adj(numCourses);
        for(vector<int> v : prerequisites){
            adj[v[0]].push_back(v[1]);
        }
        int ok = true;
        for(int i = 0; i < numCourses; i++){
            k.clear();
            k.resize(i);
            ok = (!dfs(k, adj, i)) ? false : ok;
        }
        return ok;
    }
private:
    bool dfs(vector<bool>& visited, vector<vector<int>>& prerequisites, int i){
        if(visited[i]) return false;
        for(int j : prerequisites[i]){
            visited[i] = true;
            if(!dfs(visited, prerequisites, j)) return false;
            visited[i] = false;
        }
        return true;
    }
};