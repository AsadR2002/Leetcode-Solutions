class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //start at 0 and keep count of how many times that number has appeared 
        int count = 1; 
        int cand = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0) cand = nums[i];

            if(nums[i] == cand) count++; 
            else count--;
            //this will work because the element is the majority, so count of that - all other numbers 
            //count will be >=1
        }

        return cand;
        
    }
};