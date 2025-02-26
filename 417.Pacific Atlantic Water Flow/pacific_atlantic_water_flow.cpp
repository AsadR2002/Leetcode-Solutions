class Solution {
    public:
        set<pair<int, int>> pac; 
        set<pair<int, int>> atl; 
    
        void dfs(int r, int c, set<pair<int, int>>& visit, vector<vector<int>>& heights, int prevHeight, int ROWS, int COLS) {
            if(visit.find({r, c})!= visit.end() || r < 0 || c < 0 || 
            r == ROWS || c == COLS|| heights[r][c] < prevHeight) return;
    
            visit.insert({r, c}); 
            dfs(r + 1, c, visit, heights, heights[r][c], ROWS, COLS);
            dfs(r - 1, c, visit, heights, heights[r][c], ROWS, COLS);
            dfs(r, c + 1, visit, heights, heights[r][c], ROWS, COLS);
            dfs(r, c - 1, visit, heights, heights[r][c], ROWS, COLS);
        }
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            const int ROWS = heights.size(); 
            const int COLS = heights[0].size(); 
     
            for(int c = 0; c < COLS; c++) {
                dfs(0, c, pac, heights, heights[0][c], ROWS, COLS); 
                dfs(ROWS-1, c, atl, heights, heights[ROWS-1][c], ROWS, COLS);
            }
    
            for(int r = 0; r < ROWS; r++) {
                dfs(r, 0, pac, heights, heights[r][0], ROWS, COLS); 
                dfs(r, COLS-1, atl, heights, heights[r][COLS-1], ROWS, COLS); 
            }
    
            vector<vector<int>> res;
    
            for(int r = 0; r < ROWS; r++) {
                for(int c = 0; c < COLS; c++) {
                    if(pac.find({r, c})!= pac.end() && atl.find({r, c})!= atl.end()) {
                        res.push_back({r, c});
                    }
                }
            }
    
            return res;    
        }
};