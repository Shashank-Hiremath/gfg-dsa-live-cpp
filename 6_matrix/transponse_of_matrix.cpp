//https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1

class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        int numRows = matrix.size();
        if(numRows == 0){
            return;
        }
        int numCols = matrix[0].size();
        int rowNo, colNo;
        for(rowNo=0;rowNo<numRows;rowNo++){
            for(colNo=rowNo+1;colNo<numCols;colNo++){
                swap(matrix[rowNo][colNo], matrix[colNo][rowNo]);
            }
        }
        return ;
    }
};