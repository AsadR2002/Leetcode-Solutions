class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res; 
            int TOP = 0;
            int BOT = matrix.size(); 
            int LEFT = 0; 
            int RIGHT = matrix[0].size(); 
    
            while(TOP < BOT && RIGHT > LEFT) {
                for(int i = LEFT; i < RIGHT; i++) {
                    res.push_back(matrix[TOP][i]);
                }
                TOP++;
                for(int i = TOP; i < BOT; i++) {
                    res.push_back(matrix[i][RIGHT - 1]);
                }
                RIGHT--;
    
                if(LEFT >=RIGHT || TOP >= BOT) break; 
    
                for(int i = RIGHT-1; i >= LEFT; i--) {
                    res.push_back(matrix[BOT-1][i]);
                }
                BOT--;
    
                for(int i = BOT-1; i >= TOP; i--) {
                    res.push_back(matrix[i][LEFT]);
                }
                LEFT++; 
                   
            }
            return res;   
        }
};