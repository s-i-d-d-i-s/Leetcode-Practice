class Solution {
public:
    int dp[14][10005];
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int result = coinChangeUtil(0,coins,amount);
        if(result == INT_MAX)result=-1;
        return result;
    }
    
    int coinChangeUtil(int idx,vector<int>& coins, int amount) {
        if(idx>=coins.size()){
            return amount==0?0:INT_MAX;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        if(coins[idx]<=amount){
            int pos1 = coinChangeUtil(idx,coins,amount-coins[idx]);
            if(pos1!=INT_MAX)pos1++;
            int pos2 = coinChangeUtil(idx+1,coins,amount-coins[idx]);
            if(pos2!=INT_MAX)pos2++;
            int pos3 = coinChangeUtil(idx+1,coins,amount);
            return dp[idx][amount]=min({pos1,pos2,pos3});
        }else{
            return dp[idx][amount]=coinChangeUtil(idx+1,coins,amount);
        }
    }
};