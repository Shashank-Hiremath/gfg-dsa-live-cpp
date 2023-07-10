//https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1


// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}// } Driver Code Ends
// User function template for C++

int MissingNumber(vector<int>& array, int n) {
    // return n*(n+1)/2 - accumulate(array.begin(), array.end(), 0);
    int i, ans=0;
    for(i=1;i<=n-1;i++)
        ans ^= array[i-1]^i;
    return ans^n;
}