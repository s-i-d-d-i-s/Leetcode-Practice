class Solution {
public:
    int dp[201][201];
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
        
        return solve(1,n);
    }
    int solve(int l,int r){
        if(l>=r)return 0;    
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int result = INT_MAX;
        for(int i=l;i<=r;i++){
            int current = i+max(solve(l,i-1),solve(i+1,r));
            result = min(result,current);
        }        
        return dp[l][r]=result;;
    }
};