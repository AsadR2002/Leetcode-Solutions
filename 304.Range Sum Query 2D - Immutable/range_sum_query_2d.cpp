class NumMatrix {
    public:
        vector<vector<int>> sumMat;
        NumMatrix(vector<vector<int>>& matrix) {
            int ROWS = matrix.size(), COLS = matrix[0].size();
    
            sumMat = vector<vector<int>>(ROWS+1, vector<int>(COLS+1, 0));
    
            for(int r = 0; r < ROWS; r++){
                int prefix = 0;
                for(int c = 0; c < COLS; c++){
                    prefix += matrix[r][c];
                    int above = sumMat[r][c+1];
                    sumMat[r+1][c+1] = prefix + above;
                }
            }
    
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            int r1 = row1+1, r2 = row2+1, c1 = col1+1, c2 = col2+1;
    
            int br = sumMat[r2][c2];
            int above = sumMat[r1-1][c2];
            int left = sumMat[r2][c1 - 1];
            int tl = sumMat[r1-1][c1-1];
    
            return br - above - left + tl;
            
        }
};
    
    /**
     * Your NumMatrix object will be instantiated and called as such:
     * NumMatrix* obj = new NumMatrix(matrix);
     * int param_1 = obj->sumRegion(row1,col1,row2,col2);
     */