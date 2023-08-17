//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

int rotOranges(vector<vector<int> > matrix, int R, int C)
{
    int i, j, k, i1, j1, row[4]={0, -1, 0, 1}, col[4]={1, 0, -1, 0}, size, t=0;
    queue<pair<int, int>> q;
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            if(matrix[i][j]==2)
                q.push({i, j});
    while(!q.empty())
    {
        for(size=q.size();size;size--)
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(k=0;k<4;k++)
            {
                i1 = i + row[k];
                j1 = j + col[k];
                if(i1>=0 && i1<R && j1>=0 && j1<C && matrix[i1][j1]==1)
                {
                    matrix[i1][j1] = 0;
                    q.push({i1, j1});
                }
            }
        }
        t++;
    }
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            if(matrix[i][j]==1)
                return -1;
    return t-1;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends