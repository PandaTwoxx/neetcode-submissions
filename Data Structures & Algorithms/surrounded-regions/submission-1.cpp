class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> marked(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) checkCells(i, 0, n, m, marked, board);
        for(int i = 0; i < n; i++) checkCells(i, m-1, n, m, marked, board);
        for(int j = 0; j < m; j++) checkCells(0, j, n, m, marked, board);
        for(int j = 0; j < m; j++) checkCells(n-1, j, n, m, marked, board);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!marked[i][j]) board[i][j] = 'X';
                else board[i][j] = 'O';
            }
        }

    }
private:
    int checkCells(int i, int j, int n, int m, vector<vector<bool>>& marked, vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(board[i][j] == 'X' || marked[i][j]) return 0;

        marked[i][j] = true;

        checkCells(i+1, j, n, m, marked, board);
        checkCells(i-1, j, n, m, marked, board);
        checkCells(i, j+1, n, m, marked, board);
        checkCells(i, j-1, n, m, marked, board);

        return 0;
    }
};
