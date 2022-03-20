class Solution {
public:
    int dp[10][10][1024];
    int countNumbersWithUniqueDigits(int n) {
        int result=1;
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++){
            result += (count(0,i,0));
        }
        return result;
    }
    int count(int idx,int n,int mask){
        if(idx>=n){
            return 1;
        }
        if(dp[idx][n][mask] != -1){
            return dp[idx][n][mask];
        }
        int result = 0;
        for(int i=0;i<=9;i++){
            if(idx==0 and i==0)continue; 
            if(mask & (1<<i)) continue;
            result += count(idx+1,n,mask | (1<<i));
        }
        return dp[idx][n][mask] = result;
    }
};