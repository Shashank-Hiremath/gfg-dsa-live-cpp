//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1


class Solution
{   
    void borderTraversal(vector<vector<int>>& matrix, int r1, int r2, int c1, int c2, vector<int> &ans){
        int r, c;
        for(c=c1;c<=c2;c++)
            ans.push_back(matrix[r1][c]);
        for(r=r1+1;r<=r2;r++)
            ans.push_back(matrix[r][c2]);
        if(r1<r2 && c1<c2)
        {
            for(c=c2-1;c>=c1;c--)
                ans.push_back(matrix[r2][c]);
            for(r=r2-1;r>=r1+1;r--)
                ans.push_back(matrix[r][c1]);
        }
    }
    
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> ans;
        borderTraversal(matrix, 0, n-1, 0, m-1, ans);
        return ans;
    }
};