class Solution {
public:
    int dp[1001][101][2];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int maxProfit(int k, vector<int>& prices,int idx=0,bool buy=true) {
        if(idx>=prices.size() or (buy and k==0))
            return 0;
        
        if(dp[idx][k][buy] != -1)
            return dp[idx][k][buy];
        
        int doNothing = maxProfit(k,prices,idx+1,buy);
        int doTrade = prices[idx]*(buy?-1:1) + maxProfit(k-(buy?1:0),prices,idx+1,!buy);
        
        return dp[idx][k][buy] = max(doNothing,doTrade);
    }
};