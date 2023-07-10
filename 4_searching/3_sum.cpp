//https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int k = 0, i, l, r, n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(i=n-1;i-2>=0;i--)
        {
            l = 0;
            r = i-1;
            while(l<r)
            {
                if(nums[l] + nums[r] + nums[i] > k)
                {
                    r--;
                    while(l<r && nums[r] == nums[r+1])
                        r--;
                }
                else if(nums[l] + nums[r] + nums[i] < k)
                {
                    l++;
                    while(l<r && nums[l-1]==nums[l])
                        l++;
                }
                else
                {
                    ans.push_back({nums[l], nums[r], nums[i]});
                    
                    r--;
                    while(l<r && nums[r] == nums[r+1])
                        r--;
                    
                    l++;
                    while(l<r && nums[l-1]==nums[l])
                        l++;
                }
            }
            while(i-1>=0 && nums[i-1]==nums[i])
                i--;
        }
        return ans;
    }
};