//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);


 // } Driver Code Ends
//User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
int row[4] = {0,-1,0,1}, col[4] = {1,0,-1,0};
char dir[4] = {'R', 'U', 'L', 'D'};
void f(int m[MAX][MAX], int n, int i, int j, string s,
vector<string> &ans, vector<vector<bool>> &vis)
{
    if(i==n-1 && j==n-1)
        ans.push_back(s);
    else
        for(int x=0;x<4;x++)
        {
            int i1 = i + row[x];
            int j1 = j + col[x];
    if(i1>=0 && i1<n && j1>=0 && j1<n && m[i1][j1] && !vis[i1][j1])
            {
                vis[i1][j1] = 1;
                f(m, n, i1, j1, s+dir[x], ans, vis);
                vis[i1][j1] = 0;
            }
        }
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> ans;
    if(m[0][0]==0)  return ans;
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    vis[0][0] = 1;
    f(m, n, 0, 0,"", ans, vis);
    sort(ans.begin(), ans.end());
    return ans;
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int m[MAX][MAX];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>m[i][j];
			}
		}
		
		vector<string> result = printPath(m,n);
		if(result.size() == 0)
			cout<<-1;
		else
			for(int i=0;i<result.size();i++)
				cout<<result[i]<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends