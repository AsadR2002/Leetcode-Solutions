class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            set<int> elements(nums.begin(), nums.end());
    
            int longest = 0;
            for(int i : elements){
                if(elements.find(i - 1) == elements.end()) { 
                    int count = 1; 
                    while(elements.find(i + count) != elements.end()) count++;
                    longest = max(count, longest);
                }
            }
            return longest;   
        }
};