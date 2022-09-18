
class Solution {
public:
    

    bool is_unique_box(vector<vector<char>>& board, int n, int m){
        unordered_map<char,int> mp;
        for(int i = n; i < n + 3; i++){
            for(int j = m; j < m + 3; j++){
                if (board[i][j] == '.') 
                    continue;
                if (mp[board[i][j]] == 1) 
                    return false;
                mp[board[i][j]]++;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<char,int> mp;

        // check every row if there is more than one occurrence of a number 
        for (vector<char> row : board){
            for(char c: row) {
                if (c == '.') 
                    continue;
                if (mp[c] == 1) { 
                    return false;
                }
                else 
                    mp[c]++;
            }
            mp.clear();
        }
        // check every column if there is more than one occurrence of a number 
        for (int i = 0; i < 9; i++){
            mp.clear();
            for(int j = 0; j < 9; j++){
                if (board[j][i] == '.') 
                    continue;
                if (mp[board[j][i]] == 1) 
                    return false;
                mp[board[j][i]]++;
            }
        }
        
        // check every 3x3 box
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!is_unique_box(board, i, j)){
                    return false;
                }
            }
        }
        
        return true;
    }

};