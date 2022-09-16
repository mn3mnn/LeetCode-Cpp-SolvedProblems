class Solution {
public:
   
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = 0, n = 0;
    int rows = mat.size(), columns = mat[0].size();
    vector<vector<int>> shaped(r, vector<int>(c, 0));

    if (rows * columns != r * c) {
        return mat;
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            shaped[m][n++] = mat[i][j];
            if (n == c){
                m++;
                n = 0;
            }
        }
    }
    return shaped;
}
};