class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& nums) {
            int l = 0, r = 0; 
            while(r < nums.size()) {
                if(nums[r] %2 == 0){
                    std::swap(nums[l], nums[r]);
                    l++;
                }
                r++;
            }
            return nums;
        }
    };