//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//User function template for C++

class Solution{
    public:
    int partition(int arr[], int l, int r){
        int i = l-1, j;
        for(j=l;j<=r-1;j++){
            if(arr[j] < arr[r]){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[r]);
        return i+1;
    }
    
    int myKthSmallest(int arr[], int l, int r, int k) {
        if(l<=r){
            int pi = partition(arr, l, r);
            if(pi < k){ //Move searching to right side
                myKthSmallest(arr, pi+1, r, k);
            }else if(pi > k){ //Move searching to left side
                myKthSmallest(arr, l, pi-1, k);
            }else{
                return arr[pi];
            }
        }
    }
    //Not used only for comparison
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now at right place */
            int pi = partition(arr, low, high);
            // Separately sort elements before partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // int n = r+1;
        // k--;
        // nth_element(arr+l, arr+k, arr+n);
        // return arr[k];
        return myKthSmallest(arr, l, r, k-1);
    }
};