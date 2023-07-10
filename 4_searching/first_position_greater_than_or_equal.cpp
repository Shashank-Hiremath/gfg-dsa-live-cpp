//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    int firstPositionGreaterThanOrEqual(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, mid, hi = n;
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid] < target){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return lo;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        // auto lb = lower_bound(nums.begin(), nums.end(), target);
        // if(find(nums.begin(), nums.end(), target) == nums.end()){
        //     return {-1, -1};
        // }
        // auto ub = upper_bound(nums.begin(), nums.end(), target);

        // int first = lb - nums.begin();
        // int last = ub - nums.begin() - 1;

        // return {first, last};

        int first = firstPositionGreaterThanOrEqual(nums, target);
        if(first <0 || first >= nums.size() || nums[first] != target){
            return {-1, -1};
        }
        int last = firstPositionGreaterThanOrEqual(nums, target+1)-1;

        return {first, last};
    }
};