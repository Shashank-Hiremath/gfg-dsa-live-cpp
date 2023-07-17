//https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1

class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int a[], int n)
    {
       //Your code here
       int zeros=0, ones=n-1;
       while(zeros<=ones){
           if(a[zeros] == 1){
               swap(a[zeros], a[ones]);
               ones--;
           }else{
               zeros++;
           }
       }
       /**************
        * No need to print the array
        * ************/
    }
};