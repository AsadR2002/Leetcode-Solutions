class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int res = *std::max_element(nums.begin(), nums.end());
    
            int cur_min = 1, cur_max = 1; 
    
            for(int n : nums){ 
                if(n == 0) {
                    cur_min = 1; 
                    cur_max = 1;
                }
                int temp = cur_max; 
                cur_max = max({n * cur_max, n * cur_min, n}); 
                cur_min = min({n * temp, n * cur_min, n}); 
    
                res = max(res, cur_max);
    
            }
    
            return res;
            
        }
    };