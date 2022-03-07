int dp[10005];
bool init = false;
class Solution {
public:
    
    
    Solution(){
        if(!init){
            memset(dp,-1,sizeof dp);
            init=1;
        }
    }
    int numSquares(int n) {
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        int result = INT_MAX;
        for(int i=1;i*i<=n;i++){
            int recurSolution = numSquares(n-i*i);
            if(recurSolution == INT_MAX) continue;
            result = min(result,1+recurSolution);
        }
        return dp[n]=result;
    }
};