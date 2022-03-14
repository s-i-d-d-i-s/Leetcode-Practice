class Solution {
public:
    int dp[100];
    int integerBreak(int n) {
        memset(dp,-1,sizeof dp);
        if(n==2) return 1;
        if(n==3) return 2;
        int result = breakIt(n);
        return result;
    }
    
    int breakIt(int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        int result=0;
        for(int i=1;i<=n;i++){
            int current = i*breakIt(n-i);
            result = max(result,current);
        }
        return dp[n] = result;
    }
};