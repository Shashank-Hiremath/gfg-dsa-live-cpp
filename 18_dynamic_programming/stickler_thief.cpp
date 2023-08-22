//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends
// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    int i;
    for(i=0;i<n;i++)
        if(i>=2)
            arr[i] = max(arr[i] + arr[i-2], arr[i-1]);
        else if(i==1)
            arr[i] = max(arr[i], arr[i-1]);
    return arr[n-1];
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends