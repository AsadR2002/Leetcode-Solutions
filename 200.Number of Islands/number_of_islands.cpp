class Solution {
    public:
        set<pair<int, int>> visited;
        void dfs(int r, int c,vector<vector<char>>& grid, int ROWS, int COLS) {
    
            if(visited.find({r, c}) != visited.end() || r < 0 || c < 0 || r == ROWS || c == COLS) return;
    
            if(grid[r][c] == '0') return;
    
            if(grid[r][c] == '1') {
                visited.insert({r, c});
                dfs(r + 1, c, grid, ROWS, COLS); 
                dfs(r - 1, c, grid, ROWS, COLS); 
                dfs(r, c + 1, grid, ROWS, COLS); 
                dfs(r, c - 1, grid, ROWS, COLS); 
    
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty()) return 0; // Handle empty grid case
            int islands = 0; 
            const int ROWS = grid.size(); 
            const int COLS = grid[0].size();
    
            for(int r = 0; r < ROWS; r++) {
                for(int c = 0; c < COLS; c++) {
                    // check that r and c have not been visited as part of other islands 
                    if(grid[r][c] == '1' && visited.find({r, c}) == visited.end()) {
                        dfs(r, c, grid, ROWS, COLS); 
                        islands++;
                    }
                }
            }
            return islands; 
        }
    };
    /*
    we start at the top right and iterate through every point, we have a pair set of every visited node, if we come across a 1, we run dfs until we have touched eveyr adjacent node and then increment the count */