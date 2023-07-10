//https://leetcode.com/problems/4sum/submissions/763363617/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=n-1;i-3>=0;i--)
        {
            for(int j=i-1;j-2>=0;j--)
            {
                int l = 0;
                int r = j-1;
                while(l<r)
                    if(0LL + nums[l] + nums[r] + nums[j] + nums[i] < target + 0LL)
                    {
                        l++;
                        while(l<r && nums[l-1]==nums[l])
                            l++;
                    }
                    else if(0LL + nums[l] + nums[r] + nums[j] + nums[i] + 0LL > target + 0LL)
                    {
                        r--;
                        while(l<r && nums[r] == nums[r+1])
                            r--;
                    }
                    else
                    {
                        ans.push_back({nums[l], nums[r], nums[j], nums[i]});
                        
                        l++;
                        while(l<r && nums[l-1]==nums[l])
                            l++;
                    }
                while(j-1>=0 && nums[j-1] == nums[j])
                    j--;
            }
            while(i-1>=0 && nums[i-1]==nums[i])
                i--;
        }
        return ans;
    }
};