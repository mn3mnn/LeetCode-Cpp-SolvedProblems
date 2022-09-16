class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int buy_pr = prices[0], max_profit = 0;
        
        for (int i = 1; i < sz; i++) {
            
            if (buy_pr > prices[i]){
                buy_pr = prices[i];
            }
            else if ((prices[i] - buy_pr) > max_profit){
                max_profit = prices[i] - buy_pr;
            }
        }    
        return max_profit;
    }
};