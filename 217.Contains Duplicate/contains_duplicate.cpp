class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> n; 
    
            for(int c: nums) {
                if(n.count(c)) {
                    return true;
                }
    
                else{ 
                    n.insert(c);
                }
            }
    
            return false;
        }
    };