//https://practice.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1



class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        int m = matrix.size(), i;
        vector<int> ans;
        if(m == 0){
            return ans;
        }
        int n = matrix[0].size(), j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                // int j1 = (n-1)*(i&1) - j*(2*(i&1) - 1);
                int j1 = i&1 ? n-1-j : j;
                ans.push_back(matrix[i][j1]);
            }
        }

        //// Simple version
        // for(i=0;i<m;i++){
        //     if(i%2 == 0){
        //         for(j=0;j<n;j++){
        //             ans.push_back(matrix[i][j]);
        //         }
        //     }else{
        //         for(j=n-1;j>=0;j--){
        //             ans.push_back(matrix[i][j]);
        //         }
        //     }
        // }

        return ans;
    }
};