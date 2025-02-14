class Solution {
    public:
        char findTheDifference(string s, string t) {
            int sum_s = 0, sum_tt = 0;
    
            for(char c : s) {
                sum_s += (int)c;
            }
    
            for(char c : t) {
                sum_tt += (int)c;
            }
    
            int diff = sum_tt - sum_s; 
    
            return (char)diff;
            
        }
    };