//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution{   
public:
    // long subarraySum(vector<int> &arr, int start, int end){
    //     long ans = 0;
    //     for(int i=start;i<end;i++)
    //         ans += arr[i];
    //     return ans;
    // }
    long maximumSumSubarray(int k, vector<int> &arr , int n){

        // long ma = INT_MIN, i;
        // for(i=0;i<=n-k;i++)
        //     ma = max(ma, subarraySum(arr, i, i+k));
        // return ma;
        
        long ma = INT_MIN, currSum=0, i, j;
        
        for(i=0;i<k;i++)
            currSum += arr[i];
        
        ma = currSum;
        for(i=k;i<n;i++){
            currSum += arr[i];
            currSum -= arr[i-k];
            ma = max(ma, currSum);
            
            // currSum += arr[i]-arr[i-k];
            // ma = max(ma, currSum);
        }
        return ma;
    }
};