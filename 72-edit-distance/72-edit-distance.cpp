class Solution {
public:
    int min(int a, int b, int c){
        return std::min(std::min(a, b), c);
    }
    
   int minDistance(string str1, string str2){
       
    int gapCost = 1, mismatchCost = 1; 

    int len1 = str1.length();
    int len2 = str2.length();

    // table of costs
    int DP [len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {

            // If first string is empty, the only option is to
            // insert all characters of the other string
            // number of ops (cost) = the len of the other string
            if (i == 0){
                DP[i][j] = j * gapCost;
            }

            // If second string is empty, the only option is to
            // insert all characters of the other string
            // number of ops (cost) = the len of the other string
            else if (j == 0)
            {
                DP[i][j] = i * gapCost;
            }

            else {
                // 0 cost for match
                int misCost = (str1[i - 1] == str2[j - 1] ? 0 : mismatchCost);

                DP[i][j] = min(DP[i - 1][j - 1] + misCost,// diagonal (replace)
                               DP[i - 1][j] + gapCost, // (delete)
                               DP[i][j - 1] + gapCost); // (insert)
            }
        }
    }

    return DP[len1][len2];
}
};