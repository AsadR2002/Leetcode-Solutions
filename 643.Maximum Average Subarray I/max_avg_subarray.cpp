class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int n = nums.size();
            double max_avg = -99999; 
            double cur_sum = 0;
    
            for(int i = 0; i < k; i++) {
                cur_sum += nums[i];
            }
    
            max_avg = cur_sum / k; 
    
            for(int i = k; i < n; i++) {
                cur_sum = cur_sum + nums[i] - nums[i-k]; 
                max_avg = cur_sum > max_avg * k ? cur_sum / k : max_avg;
    
            }
    
            return max_avg;    
        }
    };