class Solution {
public:
    int min(int a, int b, int c){
        return std::min(std::min(a, b), c);
    }
    
   int minDistance(string& str1, string& str2){
       
   int len1 = str1.length();
    int len2 = str2.length();

    // table of costs
    int DP [len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            // number of ops (cost) = the len of the other string
            if (i == 0){
                DP[i][j] = j;
            }
            // number of ops (cost) = the len of the other string
            else if (j == 0)
            {
                DP[i][j] = i;
            }
            else {
                // 0 cost for match, 1 for mismatch
                int matchingCost = (str1[i - 1] == str2[j - 1] ? 0 : 1);

                DP[i][j] = min(DP[i - 1][j - 1] + matchingCost,// diagonal (replace)
                               DP[i - 1][j] + 1, // (delete)
                               DP[i][j - 1] + 1); // (insert)
            }
        }
    }

    return DP[len1][len2];
}
};