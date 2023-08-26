//https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    int minDistance(string word1, string word2) {
                int m = word2.size(), n = word1.size(), i, j;
        vector<vector<int>> mat(m + 1, vector<int>(n + 1, 0));
        for (i = 1; i <= m; i++)
                    mat[i][0] = i;
        for (j = 1; j <= n; j++) 
            mat[0][j] = j;
        for (i = 1; i <= m; i++) 
            for (j = 1; j <= n; j++) 
                if (word2[i - 1] == word1[j - 1])
                    mat[i][j] = mat[i - 1][j - 1];
                else
                    mat[i][j] = min(mat[i - 1][j - 1], min(mat[i][j - 1], mat[i - 1][j])) + 1;
        return mat[m][n];
    }
};