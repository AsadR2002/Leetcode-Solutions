class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int rows = text1.length() + 1;
            int cols = text2.length() + 1;
            vector<vector<int>> dp(rows, std::vector<int>(cols, 0));
    
            for(int i = text1.length() - 1; i >= 0; i--) {
                for(int j = text2.length() - 1; j >= 0; j--) {
                    if(text1[i] == text2[j]) {
                        dp[i][j] = 1 + dp[i+1][j+1];
                    }
                    else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j + 1]);
                    }
                }
            }
            return dp[0][0];
        }
};