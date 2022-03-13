class Solution {
public:
    int dp[300][5005];
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        int result = coinChangeUtil(0,coins,amount);
        return result;
    }
    int coinChangeUtil(int idx,vector<int>& coins, int amount) {
        if(idx>=coins.size()){
            return amount==0?1:0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        
        int canTake = amount/coins[idx];
        int result=0;
        for(int i=0;i<=canTake;i++){
            int current = coinChangeUtil(idx+1,coins,amount-i*coins[idx]);
            result += current;
        }        
        return dp[idx][amount]=result;
    }
};