//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(n<=0){
            return {-1};
        }
        int left=0, right=0, sum=0;
        while(right<n){
            sum += arr[right];
            while(sum > s && left<right){
                sum -= arr[left];
                left++;
            }
            if(sum == s)
                return {left+1, right+1}; //Expected in 1 based indexing.
            right++;
        }
        return {-1};
    }
};