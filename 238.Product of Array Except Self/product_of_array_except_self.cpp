class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
    
            vector<int> output; 
            int pre_calc = 1; 
    
            for(int i = 0; i < nums.size(); i++) { 
                output.push_back(pre_calc);
                pre_calc = pre_calc * nums[i];
            }
    
            int post = 1; 
            for(int i = nums.size() - 1; i > -1; i--) { 
                output[i] = output[i] * post;
                post = post * nums[i]; 
            }
    
            return output;    
        }
    };