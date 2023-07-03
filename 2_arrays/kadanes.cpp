//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    int max_sum = arr[0], curr_sum = arr[0], i;
    for(i=1;i<n;i++)
    {
        curr_sum = max(curr_sum + arr[i], arr[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
    
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends