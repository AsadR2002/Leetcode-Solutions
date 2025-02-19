class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            // we can put all of each array in a set
            std::unordered_set<int> a1(nums1.begin(), nums1.end());
            std::unordered_set<int> a2(nums2.begin(), nums2.end());
    
            vector<vector<int>> ans; 
    
            vector<int> unique_in_1; 
            vector<int> unique_in_2; 
    
            for(int num: a1) {
                if(!a2.count(num)) unique_in_1.push_back(num);
            }
    
            for(int num: a2) {
                if(!a1.count(num)) unique_in_2.push_back(num);
            }
    
            ans.push_back(unique_in_1); 
            ans.push_back(unique_in_2); 
    
            return ans;
        }
    };