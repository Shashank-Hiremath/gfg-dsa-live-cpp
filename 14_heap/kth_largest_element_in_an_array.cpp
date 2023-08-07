//https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n: nums)
            {
                pq.push(n);
                if(pq.size()==k+1)
                    pq.pop();
            }
        return pq.top();
    }
};