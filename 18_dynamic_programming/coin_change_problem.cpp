//https://practice.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
  public:
    long long int count(int coins1[], int n, int sum) {
        vector<long long int> dp(sum+1, 0);
        vector<int> coins(coins1, coins1+n);
        dp[0] = 1;
        for(auto coin: coins)
            for(int i=coin;i<=sum;i++)
                dp[i] += dp[i-coin];
        return dp[sum];
    }
};