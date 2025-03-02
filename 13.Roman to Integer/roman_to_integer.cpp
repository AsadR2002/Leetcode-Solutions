class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char, int> syms; 
            syms['I']= 1;
            syms['V']= 5;
            syms['X']= 10;
            syms['L']= 50;
            syms['C']= 100;
            syms['D']= 500;
            syms['M']= 1000;
    
            int res = 0; 
            int subtractor = 0;
    
            for(int i = 0; i < s.length();i++){
                if((i+1) < s.length()) {
                    if(syms[s[i+1]] > syms[s[i]]) res -= syms[s[i]];
                    else res += syms[s[i]];
                }
                else {
                    res += syms[s[i]];
                }
            }
    
    
            return res;
            
        }
};