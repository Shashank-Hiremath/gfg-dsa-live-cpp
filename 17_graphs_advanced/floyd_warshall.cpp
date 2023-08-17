//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int i, j, via, n = matrix.size();
	    
        for(via=0;via<n;via++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    if(matrix[i][via]!=-1 && matrix[via][j]!=-1){
                        if(matrix[i][j] == -1)
                            matrix[i][j] = matrix[i][via] + matrix[via][j];
                        else
                            matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
	}
};