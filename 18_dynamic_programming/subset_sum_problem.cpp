//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size(), i, j;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        dp[0][0] = 1;
        for(i=0;i<n;i++)
            for(j=0;j<=sum;j++)
                if(j>=arr[i])
                    dp[i+1][j] = dp[i][j] || dp[i][j-arr[i]];
                else
                    dp[i+1][j] = dp[i][j];
        return dp.back().back();
    }
};