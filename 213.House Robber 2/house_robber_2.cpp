class Solution {
    public:
        int rob1(vector<int>& nums) {
            int rob1 = 0, rob2 = 0;
            for(int n : nums) {
                int temp = max(rob1 + n, rob2); 
                rob1 = rob2;
                rob2 = temp; 
            }
            return rob2;
        }
        int rob(vector<int>& nums) {
            if(nums.size() == 1) {
                return nums[0];
            }
            vector<int> subvec1(nums.begin(), nums.end() - 1); 
            vector<int> subvec2(nums.begin() + 1, nums.end()); 
    
            return max(rob1(subvec1), rob1(subvec2));
            
        }
};