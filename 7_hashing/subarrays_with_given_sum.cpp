//https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1

class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
        unordered_map<int, int> prefixSumFrequency;
        prefixSumFrequency[0]=1;
        int prefixSum = 0, ans=0, i;
        for(i=0;i<n;i++){
            prefixSum += arr[i];
            int target = prefixSum-sum;
            if(prefixSumFrequency.find(target) != prefixSumFrequency.end()){ //If previously target was there
                ans += prefixSumFrequency[target];
            }
            prefixSumFrequency[prefixSum]++;
        }
        return ans;
    }
};