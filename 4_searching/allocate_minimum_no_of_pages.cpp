//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//User function template in C++

class Solution 
{
    public:
    
    int numberOfStudentsRequired(int a[], int n, int maxPages){
        int requiredStudents = 1, currentTotalPages=0;
        for(int i=0;i<n;i++){
            currentTotalPages += a[i];
            
            if(currentTotalPages > maxPages){
                requiredStudents++;
                currentTotalPages = a[i];
            }
        }
        return requiredStudents;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        if(m > n){
            return -1;
        }
        int max_val=*max_element(a, a+n), sum_array = accumulate(a, a+n, 0), possibleAnswer;
        int lo = max_val, hi = sum_array, mid = possibleAnswer;
        while(lo<hi){
            mid = lo + (hi - lo)/2;
            int requiredStudents = numberOfStudentsRequired(a, n, mid);
            
            if(requiredStudents > m){ //maxPages should be increased
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return lo;
    }
};