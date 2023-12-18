//https://leetcode.com/problems/next-greater-element-ii/description/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a(nums);
        a.insert(a.end(), nums.begin(), nums.end());
        stack<int> s;
        int n = nums.size(), i;
        vector<int> ans(n, -1);
        for(i=0;i<2*n;i++)
        {
            while(!s.empty() and nums[s.top()] < a[i])
            {
                ans[s.top()] = a[i];
                s.pop();
            }
            if(i<n)
                s.push(i);
        }
        return ans;
    }
};