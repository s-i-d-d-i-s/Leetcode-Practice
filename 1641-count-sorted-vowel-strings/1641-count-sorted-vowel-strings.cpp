class Solution {
public:
	int dp[50][6];
    int solve(int idx,int n,int k){
        if(idx>=n){
            return 1;
        }
        if(dp[idx][k]!=-1){
        	return dp[idx][k];
        }
        int res=0;
        for(int i=k;i<=5;i++){
            res += solve(idx+1,n,i);
        }
        return dp[idx][k]=res;
    }
    int countVowelStrings(int n) {
    	memset(dp,-1,sizeof dp);
        return solve(0,n,1);
    }
};