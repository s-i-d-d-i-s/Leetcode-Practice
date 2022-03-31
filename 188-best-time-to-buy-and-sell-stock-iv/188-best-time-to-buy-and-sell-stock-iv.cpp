class Solution {
public:
    int dp[1001][101];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int maxProfit(int k, vector<int>& prices,int idx=0) {
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        int mini = prices[idx];
        
        int result=maxProfit(k,prices,idx+1);
        
        for(int i=idx+1;i<prices.size() and k>0;i++){
            result = max(result,prices[i]-mini + maxProfit(k-1,prices,i+1));
        }
        return dp[idx][k]=result;
    }
};