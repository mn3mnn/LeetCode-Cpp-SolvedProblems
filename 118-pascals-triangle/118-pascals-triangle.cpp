class Solution {
public:

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> pascal(numRows);

        pascal[0].push_back(1);

        if (numRows < 2){
            return pascal;
        }

        pascal[1].push_back(1);
        pascal[1].push_back(1);

        for (int i = 2; i < numRows; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i){
                    pascal[i].push_back(1);
                }
                else{
                    pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
                }
            }
        }
        return pascal;
    }

};