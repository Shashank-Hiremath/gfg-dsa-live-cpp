//https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/1

//User function Template for C++

class Solution
{
public:
void f(vector<int> &arr, int n, int i, int &ans){
    if(i >= n){
        return;
    }
    if(arr[i] > ans){
        ans = arr[i];
    }
    f(arr, n, i+1, ans);
}
    int largest(vector<int> &arr, int n)
    {
        if(n == 0){
            return -1;
        }
        
        ////Iterative
        // int ans = arr[0];
        // for(int i=1;i<n;i++){
        //     if(arr[i] > ans){
        //         ans = arr[i];
        //     }
        // }
        // return ans;
        
        ////Recursive
        int ans = INT_MIN;
        f(arr, n, 0, ans);
        
        return ans;
    }
};