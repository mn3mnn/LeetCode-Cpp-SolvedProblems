class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        int L = 0, R = nRows * nCols - 1;

        while (L <= R){
            int M = L + (R - L) / 2;
            // n is column's number for M-th element in the matrix  
            int n = M % nCols;
            // m is row's number for M-th element in the matrix
            int m = 0;
            for (int i = nCols - 1; i < M; i += nCols) {
                m++;
            }

            if (matrix[m][n] == target){
                return true;
            } 
            else if(target < matrix[m][n]){
                R = M - 1;
            }
            else{
                L = M + 1;
            }
        }
        return false;
    }
};