class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> map; 
            vector<int> res; 
            vector<vector<int>> freq(nums.size() + 1);
    
            for(int i = 0; i < nums.size(); i++) {
                if(map.find(nums[i]) != map.end()) map[nums[i]]++; 
                else map[nums[i]] = 1;
            }
    
            for(auto [n, c] : map) {
                freq[c].push_back(n);
            }
    
            for(int i = freq.size() - 1; i >= 0; i--) {
                for(int n : freq[i]) res.push_back(n); 
                if(res.size() == k)return res;
            }
            return res;
        }
};