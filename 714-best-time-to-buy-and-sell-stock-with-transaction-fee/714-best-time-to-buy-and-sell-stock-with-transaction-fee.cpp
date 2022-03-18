class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int min_profit_when_already_bought[n];
        int max_profit_when_already_sold[n];
        
        min_profit_when_already_bought[0] = -prices[0];
        max_profit_when_already_sold[0] = 0;
        for(int i=1;i<n;i++){
            
            /*
                min profit if we buy today           -> 1. Don't buy i.e use last day's buy min
                                                     -> 2. Buy today i.e use last day's sell max
            */
            min_profit_when_already_bought[i] = max(
                                                    min_profit_when_already_bought[i-1],
                                                    max_profit_when_already_sold[i-1]-prices[i]
                                                );
            
            /*
                max profit if we sell today           -> 1. Don't sell i.e use last day's sell max
                                                      -> 2. Sell today i.e use last day's buy max
            */
            max_profit_when_already_sold[i] = max(
                                                    max_profit_when_already_sold[i-1],
                                                    min_profit_when_already_bought[i-1]+prices[i]-fee
                                                );
        }
        
        return max_profit_when_already_sold[n-1];
    }
};