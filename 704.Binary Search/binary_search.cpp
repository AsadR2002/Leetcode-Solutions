class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1; 
    
            while(left <= right) { 
                int index = (left + right) / 2; 
    
                if(nums[index] == target) {
                    return index; 
                }
    
                if(nums[index] < target) {
                    left = index + 1; 
                }
    
                else {
                    right = index - 1;
                }
            }
    
            return -1;
            
        }
    };