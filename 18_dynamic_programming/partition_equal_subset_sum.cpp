//https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), j;
        bitset<5001> bits(1);
        for(auto n: nums)
            bits |= bits<<n;
        return !(sum&1) && bits[sum>>1];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), j;
        if(sum&1)
            return 0;
        vector<bool> dp(sum/2+1, 0);
        dp[0] = 1;
        for(auto num: nums)
            for(j=sum/2;j-num>=0;j--)
                dp[j] = dp[j] || dp[j-num];
        return dp[sum/2];
    }
};