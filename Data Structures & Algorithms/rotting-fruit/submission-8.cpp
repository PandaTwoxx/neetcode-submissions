class Solution {
private:
    bool checkFreshFruitRem(vector<vector<int>>& grid){
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) return true;
            }
        }
        return false;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }
        int max_t = 0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = get<0>(curr);
            int j = get<1>(curr);
            int t = get<2>(curr);

            if(t > max_t){
                max_t = t;
            }

            if(i > 0){
                if(grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1, j, t+1});
                }
            }
            if(i < grid.size()-1){
                if(grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1, j, t+1});
                }
            }
            if(j > 0){
                if(grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1, t+1});
                }
            }
            if(j < grid[0].size()-1){
                if(grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i, j+1, t+1});
                }
            }
        }

        if(checkFreshFruitRem(grid)) return -1;
        return max_t;
    }
};
