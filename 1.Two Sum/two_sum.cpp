class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dig;
        for(int i = 0; i < nums.size(); i++){
            if (dig.count(target - nums[i])) {
                return {i, dig[target - nums[i]]};
            }
            dig[nums[i]] = i;
        }
        return {};  
    }
};