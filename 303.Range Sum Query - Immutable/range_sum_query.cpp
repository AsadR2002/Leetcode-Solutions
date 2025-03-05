class NumArray {
    public:
        vector<int> sum_arr;
        NumArray(vector<int>& nums) {
            sum_arr = vector<int>(nums.size() + 1, 0);
    
            for(int i = 0; i < nums.size(); i++){
                sum_arr[i + 1] = nums[i] + sum_arr[i];
            }
            
        }
        
        int sumRange(int left, int right) {
            return sum_arr[right+1] - sum_arr[left];
        }
};
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * int param_1 = obj->sumRange(left,right);
     */