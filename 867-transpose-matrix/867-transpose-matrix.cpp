class Solution {
public:
    
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    
    vector<vector<int>> trans(nCols, vector<int> (nRows, 0));

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {   
            // swap values
            trans[col][row] = matrix[row][col] ;
        }
    }
    return trans;
}
};