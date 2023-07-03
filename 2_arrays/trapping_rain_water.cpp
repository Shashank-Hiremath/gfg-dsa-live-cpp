//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){

    int lo = 0, hi = n-1, water = 0, leftmax=arr[0], rightmax=arr[n-1];
    while(lo<hi)
        if(arr[lo]<arr[hi])
        {
            if(arr[lo]>leftmax)
                leftmax = arr[lo];
            else
                water += leftmax - arr[lo];
            lo++;
        }
        else
        {
            if(arr[hi]>rightmax)
                rightmax = arr[hi];
            else
                water += rightmax - arr[hi];
            hi--;
        }
    return water;
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends