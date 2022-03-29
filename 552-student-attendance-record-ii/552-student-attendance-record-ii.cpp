class Solution {
public:
    int dp[100005][2][4];
    int mod = 1000000007;
    
    int checkRecord(int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,n,0,0);        
    }
    
    int solve(int idx,int n,int totalAbsent,int trailOfLate){
        
        if(idx>=n)
            return totalAbsent<2 and trailOfLate < 3;
        
        if(dp[idx][totalAbsent][trailOfLate] != -1){
            return dp[idx][totalAbsent][trailOfLate];
        }
        
        int result=0;
        
        // Decide to be absent
        if(totalAbsent+1<2){
            result += solve(idx+1,n,totalAbsent+1,0);
            result %= mod;
        }
        
        // Decide to be late
        if(trailOfLate+1 < 3){
            result += solve(idx+1,n,totalAbsent,trailOfLate+1);
            result %= mod;
        }
        
        result += solve(idx+1,n,totalAbsent,0);
        result %= mod;
        
        return dp[idx][totalAbsent][trailOfLate]=result;
    }
};