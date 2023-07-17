//https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:

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

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ans;
        if(m == 0)
            return ans;
        int n = matrix[0].size(), r1=0, r2=m-1, c1=0, c2=n-1;
        while(r1<=r2 && c1<=c2){
            borderTraversal(matrix, r1, r2, c1, c2, ans);
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};