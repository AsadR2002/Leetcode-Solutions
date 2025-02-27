class Solution {
    public:
        //set<pair<int, int>> path;
        bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
            int ROWS = board.size(), COLS = board[0].size(); 
    
            if(i == word.length()) return true; 
    
            if(r < 0 || c < 0 || 
            r >= ROWS || c >= COLS || 
            word[i] != board[r][c]) return false; 
    
            //found character 
            char temp=  board[r][c]; 
            board[r][c] = '#';
            bool res = (dfs(board, word, r + 1, c, i+1) || 
            dfs(board, word, r - 1, c, i+1) || 
            dfs(board, word, r, c + 1, i+1) || 
            dfs(board, word, r, c - 1, i+1));
            board[r][c] = temp;
    
            return res;
    
        }
        bool exist(vector<vector<char>>& board, string word) {
            int ROWS = board.size(), COLS = board[0].size();
    
            for(int r = 0; r < ROWS; r++) {
                for(int c = 0; c < COLS; c++) {
                    if(dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
    
            }
            return false;
        }
};