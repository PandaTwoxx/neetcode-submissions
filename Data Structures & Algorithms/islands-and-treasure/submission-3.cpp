class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = get<0>(curr);
            int j = get<1>(curr);
            int k = get<2>(curr);

            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) continue;
            if(grid[i][j] == -1) continue;
            if(visited[i][j]) continue;

            visited[i][j] = true;
            grid[i][j] = min(grid[i][j], k);

            q.push({i+1, j, k+1});
            q.push({i-1, j, k+1});
            q.push({i, j+1, k+1});
            q.push({i, j-1, k+1});
        }
    }
};