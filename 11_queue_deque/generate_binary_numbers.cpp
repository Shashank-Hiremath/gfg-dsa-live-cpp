//https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends


// Function to print all binary numbers upto n
void generate(ll n)
{
    queue<string> q;
    q.push("1");
    while(n--)
    {
        cout<<q.front()<<" ";
        q.push(q.front() + "0");
        q.push(q.front() + "1");
        q.pop();
    }
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		generate(n);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends