//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long int mi_diff = INT64_MAX;
        for(int i=0;i+m-1<n;i++){
            mi_diff = min(mi_diff, a[i+m-1] - a[i]);
        }
        return mi_diff;
    }   
};