class Solution {
    public:
    
        bool dfs(vector<vector<int>>& grid, int r, int c, int ROWS, int COLS) {
            if(r < 0 || r == ROWS || c < 0 || c == COLS || 
            grid[r][c] != 1) return false; 
    
            grid[r][c] = 2; 
    
            return true;
        }
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int,int>> q; 
    
            int ROWS = grid.size(), COLS = grid[0].size();
            int fresh = 0; 
            int time = 0;
    
            for(int r = 0; r < ROWS; r++){
                for(int c = 0; c < COLS; c++){
                    if(grid[r][c] == 1){
                        fresh++;
                    }
                    else if(grid[r][c] == 2) {
                        q.push({r, c});
                    }
                }
            }
    
            while(!q.empty() && fresh > 0){
                int size = q.size();
                for(int i = 0; i < size; i++) {
                    pair<int, int> temp = q.front(); 
                    int r = temp.first;
                    int c = temp.second;
                    q.pop(); 
    
                    if(dfs(grid, r + 1, c, ROWS, COLS)){
                        fresh--; 
                        q.push({r+1, c});
                    }
    
                    if(dfs(grid, r - 1, c, ROWS, COLS)){
                        fresh--; 
                        q.push({r - 1, c});
                    }
    
                    if(dfs(grid, r, c + 1, ROWS, COLS)){
                        fresh--; 
                        q.push({r, c + 1});
                    }
    
                    if(dfs(grid, r, c - 1, ROWS, COLS)){
                        fresh--; 
                        q.push({r, c - 1});
                    }
                }
                time++;
            }
    
            return fresh == 0 ? time : -1;
     
        }
};