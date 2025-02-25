class Solution {
    public:
        int climbStairs(int n) {
            int prev_val = 1; 
            int sec_prev_val = 1; 
    
            for(int i = 0; i < n - 1; i++) {
                int temp = prev_val + sec_prev_val; 
    
                sec_prev_val = prev_val; 
                prev_val = temp; 
            }
    
            return prev_val;
            
        }
};