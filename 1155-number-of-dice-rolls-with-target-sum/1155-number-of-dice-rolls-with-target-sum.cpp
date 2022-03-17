class Solution {
public:
    int dp[31][100000];
    const int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return count(0,n,k,target);
    }
    int count(int idx,int n,int k,int target,int cur=0){
        if(idx>=n){
            return cur == target;
        }
        if(cur>target) return 0;
        if(dp[idx][cur]!=-1){
            return dp[idx][cur];
        }
        int result=0;
        for(int i=1;i<=k;i++){
            result += count(idx+1,n,k,target,cur+i);
            result %= MOD;
        }
        return dp[idx][cur]=result;
    }
};