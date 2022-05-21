class Solution {
public:
    int dp[501][501][2];
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        return solve(1,1,piles,true);
    }
    
    int solve(int idx,int m,vector<int> &piles,bool isAlice){
        int n = piles.size();
        if(idx>n) return 0;
        if(dp[idx][m][isAlice] != -1){
            return dp[idx][m][isAlice];
        }
        int result= isAlice?INT_MIN:INT_MAX;
        int stonesTaken = 0;
        for(int i=idx;i<=min(n,idx+2*m-1);i++){
            stonesTaken += piles[i-1];
            int current = stonesTaken*isAlice + solve(i+1,max(m,i-idx+1),piles,isAlice^1);
            if(isAlice)
                result = max(result,current);
            else
                result = min(result,current);
        }
        return dp[idx][m][isAlice] = result;
    }
};