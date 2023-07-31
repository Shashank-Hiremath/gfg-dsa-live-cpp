//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, mi=INT_MAX, ans = 0;
        for(i=0;i<n;i++)
        {
            mi = min(mi, prices[i]);
            ans = max(ans, prices[i] - mi);
        }
        return ans;
    }
};