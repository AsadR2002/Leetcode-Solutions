class Solution {
    public:
        int numDecodings(string s) {
            vector<int> dp(s.length() + 1, 0); 
            dp[s.length()] = 1;
    
            for(int i = s.length() -1; i >= 0; i--) {
                if(s[i] == '0') dp[i] = 0; 
    
                else dp[i] = dp[i + 1];
    
                if(i + 1 < s.length() and (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))  {
                    dp[i] += dp[i + 2];
                }
            }
            return dp[0];
        }
};