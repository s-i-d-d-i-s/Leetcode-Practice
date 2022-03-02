class Solution {
public:
    int dp[20][20];
    int solve(int l,int r){
        if(l>=r)return 1;
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int res=0;
        for(int i=l;i<=r;i++){
            res+=(solve(l,i-1)*solve(i+1,r));
        }
        return dp[l][r] = res;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof dp);
        return solve(1,n);
    }
};