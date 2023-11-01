//https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1

class Solution{
public:	
	int search(int a[], int n){
	    if(n<=0)
	        return -1;
	    int ans = a[0];
	    for(int i=1;i<n;i++)
	        ans = ans ^ a[i];
	    return ans;
	}
};