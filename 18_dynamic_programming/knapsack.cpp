//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, j;
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(i=1;i<=n;i++)
        for(j=1;j<=W;j++)
            if(j-wt[i-1] >= 0)
                dp[i][j] = max(dp[i-1][j-wt[i-1]]+val[i-1], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
    return dp[n][W];
}
