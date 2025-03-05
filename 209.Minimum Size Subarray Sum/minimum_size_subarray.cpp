class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int l = 0;
    
            int res = INT_MAX; 
            int val = 0; 
    
            for(int r = 0; r < nums.size(); r++) {
                val += nums[r]; 
                while(val >= target){
                    res = min(res, r-l+1);
                    val -= nums[l]; 
                    l++;
                }
            }
    
            
    
            return res == INT_MAX ? 0 : res;
            
        }
};