//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
int row[8]={0, -1, -1, -1, 0, 1, 1, 1}, col[8]={1, 1, 0, -1, -1, -1, 0, 1};
void dfs(vector<int> A[], int m, int n, int i, int j)
{
    A[i][j] = 0;
    int i1, j1, k;
    for(k=0;k<8;k++)
    {
        i1 = i + row[k];
        j1 = j + col[k];
        if(i1>=0 && i1<m && j1>=0 && j1<n && A[i1][j1])
            dfs(A, m, n, i1, j1);
    }
}
int findIslands(vector<int> A[], int N, int M) {
    int i, j, cnt=0;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(A[i][j])
            {
                dfs(A, N, M, i, j);
                cnt++;
            }
    return cnt;
}