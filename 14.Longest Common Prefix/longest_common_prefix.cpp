class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string res = ""; 
    
            for(int i = 0; i < strs[0].length(); i++){
                for(string s: strs){
                    if(i == s.length() || s[i] != strs[0][i]) return res; 
                }
                res += strs[0][i];
            }
            return res;  
        }
};