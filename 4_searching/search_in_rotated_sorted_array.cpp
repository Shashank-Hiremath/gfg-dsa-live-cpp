//https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), i, lo=0, hi=n-1, mid, rot, realmid;
        while(lo<hi)
        {
            mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }
        rot = lo;
        lo=0;
        hi=n;
        while(lo<hi)
        {
            mid = lo + (hi-lo)/2;
            realmid = (mid + rot)%n;
            if(nums[realmid]==target)
                return realmid;
            if(nums[realmid]<target)
                lo = mid+1;
            else
                hi = mid;
        }
        return -1;
    }
};