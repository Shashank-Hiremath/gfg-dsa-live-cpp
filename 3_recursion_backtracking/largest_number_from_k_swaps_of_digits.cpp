//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void findMaximumNum(string str, int k, string& max);

// Driver code
int main() {
    int t, k;
    string str;
    cin >> t;
    while (t--) {
        cin >> k;
        cin >> str;
        string max = str;
        findMaximumNum(str, k, max);

        cout << max << endl;
    }
    return 0;
}
// } Driver Code Ends

// function to find maximum integer possible by
// doing at-most K swap operations on its digits
void findMaximumNum(string str, int k, string& max) {
    if(k==0)
        return;
    for(int i=0;i<str.length();i++)
        for(int j=i+1;j<str.length();j++)
            if(str[i]<str[j])
            {
                swap(str[i],str[j]);
                if(str>max)
                    max=str;
                findMaximumNum(str,k-1,max);
                swap(str[i],str[j]);
            }
}