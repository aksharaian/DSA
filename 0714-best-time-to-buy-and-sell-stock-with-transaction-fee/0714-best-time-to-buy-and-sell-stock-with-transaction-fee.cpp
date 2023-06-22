class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
     
        if (prices.size() <= 1) return 0;
        int days = prices.size();
        int buy[days];
        int sell[days];
        memset(buy,0,sizeof(buy));
        memset(sell,0,sizeof(sell));
        buy[0]=-prices[0];
        for (int i = 1; i<days; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]); 
            sell[i] =max(sell[i - 1], buy[i - 1] + prices[i] - fee); 
        }
        return sell[days - 1];
    }
    
};