//https://practice.geeksforgeeks.org/problems/key-pair5616/1

//User function template for C++
class Solution{
public:	
    int binarysearch(int arr[], int n, int target) {
        int lo=0, hi=n, mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid] < target){
                lo = mid + 1;
            }else if(arr[mid] > target){
                hi = mid;
            }else{ //if(arr[mid] == target)
                return mid;
            }
        }
        return -1;
    }

	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr, arr+n);
	    
	    for(int i=0;i<n;i++){
	        int res = binarysearch(arr, n, x-arr[i]);
	        if(res != -1 && res != i){
	            return true;
	        }
	    }
	    return false;
	   
	   //int lo=0, hi=n-1;
	   //while(lo<hi){
	   //    if(arr[lo] + arr[hi] < x){
	   //        lo++;
	   //    }else if(arr[lo] + arr[hi] > x){
	   //        hi--;
	   //    }else{ //arr[lo] + arr[hi] == x
	   //        return true;
	   //    }
	   //}
	   //return false;
	}
};