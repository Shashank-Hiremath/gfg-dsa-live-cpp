//https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i, j, m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for(i=0;i<obstacleGrid.size();i++)
            for(j=0;j<obstacleGrid[0].size();j++)
                if(obstacleGrid[i][j]==0)
                {
                    if(i==0 and j==0)
                        obstacleGrid[i][j] = 1;
                    if(i>0)
                        obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if(j>0)
                        obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
                else
                    obstacleGrid[i][j] = 0;
        return obstacleGrid[i-1][j-1];
    }
};