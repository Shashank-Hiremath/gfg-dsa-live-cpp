//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// Function to find longest subsequence
int longestSubsequence(int n, int a[]){
    vector<int> lis;
    int i;
    vector<int>::iterator it;
    for(i=0;i<n;i++)
        if((it = lower_bound(lis.begin(), lis.end(), a[i])) != lis.end())
            *it = a[i];
        else
            lis.push_back(a[i]);
    return lis.size();
}