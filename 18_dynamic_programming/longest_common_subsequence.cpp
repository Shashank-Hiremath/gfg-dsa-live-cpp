//https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(), i, j;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = text1[0] == text2[0];
        for(i=1;i<m;i++)
            dp[i][0] = text1[i]==text2[j] ? 1 : dp[i-1][0];
        for(j=1;j<n;j++)
            dp[0][j] = text1[0]==text2[j] ? 1 : dp[0][j-1];

        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                dp[i][j] = text1[i]==text2[j] ? 1+dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
        return dp[m-1][n-1];
        
    }
};