//https://practice.geeksforgeeks.org/problems/max-min/1

//User function Template for C++

class Solution
{
   public:
    int findSum(int a[], int n)
    {
        int mi = a[0], ma = a[0], i;
        
        for(i=1;i<n;i++){
            
            if(a[i] < mi)
                mi = a[i];
            if(a[i] > ma)
                ma = a[i];
            
            // mi = min(mi, a[i]);
            // ma = max(ma, a[i]);
        }
        return mi + ma;
        
    // 	auto minmax = minmax_element(a, a+n);
    // 	return *minmax.first + *minmax.second;
    }

};