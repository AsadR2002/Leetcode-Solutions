class Solution {
    public:
        int get_max_val(unordered_map<char, int> count) {
            int maxV = 0; 
    
            for(auto& [key, value]: count) {
                maxV = max(maxV, value);
            }
            return maxV;
    
        }
        int characterReplacement(string s, int k) {
            unordered_map<char, int> count; 
            int res = 0; 
    
            int l = 0; 
            int maxf = 0;
    
            for(int r = 0; r < s.length(); r++) {
                if(count.find(s[r]) != count.end()) count[s[r]] += 1; 
                else count[s[r]]= 1;
                maxf = max(maxf, count[s[r]]);
    
    
                while(((r-l+1) - maxf) > k) {
                    count[s[l]] -= 1;
                    l++;
                }
    
                res = max(res, r - l + 1);
            }
            return res;
            
        }
};