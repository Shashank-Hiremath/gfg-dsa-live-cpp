//https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), i, j;
        vector<bool> dp(n+1, 0);
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        dp[0] = 1;
        for(i=1;i<=n;i++)
            for(j=0;j<i;j++)
                if(dp[j] and us.find(s.substr(j, i-j))!=us.end())
                    {dp[i] = 1; break;}
        return dp[n];
                
    }
};