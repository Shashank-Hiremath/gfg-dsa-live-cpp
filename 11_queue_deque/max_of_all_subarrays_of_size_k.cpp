//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

//Using BST: https://leetcode.com/problems/sliding-window-maximum/solutions/3110955/c-using-maps-only-no-deque-easy-to-understand/
//Using priority queue: https://leetcode.com/problems/sliding-window-maximum/solutions/458121/java-all-solutions-b-f-pq-deque-dp-with-explanation-and-complexity-analysis/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void max_of_subarrays(int *arr, int n, int k){
    deque<int> dq;
    int i;
    for(i=0;i<k;i++)
    {
        while(!dq.empty() && arr[dq.back()]<=arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
    for(;i<n;i++)
    {
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<=arr[i])
            dq.pop_back();
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    max_of_subarrays(arr, n, k);
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends