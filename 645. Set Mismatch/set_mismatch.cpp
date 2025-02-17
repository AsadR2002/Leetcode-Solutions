class Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            unordered_map<int, int> map; 
            vector<int> vec;
    
            for(int i = 0; i < nums.size(); i++){ 
                if(map.count(nums[i])) {
                    map[nums[i]]+=1;
                }
                else {
                    map[nums[i]] = 1;
                }
            }
    
            for(int i = 1; i < nums.size() + 1; i++) {
                if(map[i] == 0) vec.push_back(i);
                if(map[i] == 2) vec.insert(vec.begin(), i);
            }
    
            return vec;
        }
    };