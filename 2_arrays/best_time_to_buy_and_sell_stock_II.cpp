//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, ans = 0, n = prices.size();
        for(i=0;i<n-1;i++)
            if(prices[i+1]>prices[i])
                ans += prices[i+1] - prices[i];
        return ans;
    }
};