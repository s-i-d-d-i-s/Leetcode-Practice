class Solution {
public:
    int dp[1001][2];
    const long long MOD = 1e9+7;
    int numTilings(int n) {
        memset(dp,-1,sizeof dp);
        return f(n);
    }
    long long f(int n){
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        
        if(dp[n][0]!=-1)
            return dp[n][0];
        
        return dp[n][0]=(f(n-1)+f(n-2)+2*g(n-2))%MOD;
    }
    long long g(int n){
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;  
        if(dp[n][1]!=-1)
            return dp[n][1];
        
        return dp[n][1]=(f(n-1)+g(n-1))%MOD;
    }
};