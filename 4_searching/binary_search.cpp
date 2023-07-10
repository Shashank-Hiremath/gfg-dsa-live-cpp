//https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1

class Solution {
  public:
    int binarysearch(int arr[], int n, int target) {
        int lo = 0, hi = n, i, mid;
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
};