//https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int i1=0, i2=0;
        while(i1<n && i2<m){
            if(arr1[i1] < arr2[i2]){
                if(ans.empty() || (ans.back() != arr1[i1])){
                    ans.push_back(arr1[i1]);
                }
                i1++;
            }else{
                if(ans.empty() || (ans.back() != arr2[i2])){
                    ans.push_back(arr2[i2]);
                }
                i2++;
            }
        }
        while(i1<n){
            if(ans.empty() || (ans.back() != arr1[i1])){
                ans.push_back(arr1[i1]);
            }
            i1++;
        }
        while(i2<m){
            if(ans.empty() || (ans.back() != arr2[i2])){
                ans.push_back(arr2[i2]);
            }
            i2++;
        }
        return ans;
    }
};