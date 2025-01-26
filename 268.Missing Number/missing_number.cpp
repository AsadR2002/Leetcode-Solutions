class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = size(nums);
        int val = n*(n+1) / 2;
        return val - accumulate(nums.begin(), nums.end(), 0); 
    }
};