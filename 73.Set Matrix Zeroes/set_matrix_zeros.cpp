class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            const int ROWS = matrix.size(); 
            const int COLS = matrix[0].size();
            for(int i = 0; i < ROWS; i++) {
                for(int j = 0; j < COLS; j++) {
                    if(matrix[i][j] == 0) {
                        for(int c = 0; c < COLS; c++) {
                            if(matrix[i][c] != 0) matrix[i][c] = -99999;
                        }
                        for(int r = 0; r < ROWS; r++) {
                            if(matrix[r][j] != 0) matrix[r][j] = -99999;
                        }   
                    }
                }
            }  
    
            for(int i = 0; i < ROWS; i++) { 
                for(int j = 0; j < COLS; j++) {
                    if(matrix[i][j] == -99999) matrix[i][j] = 0;
                }
            }
        }
};