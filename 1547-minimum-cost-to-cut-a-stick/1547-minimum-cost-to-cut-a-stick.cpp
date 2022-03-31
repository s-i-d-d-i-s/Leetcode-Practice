class Solution {
public:
    int dp[105][105];
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());        
        memset(dp,-1,sizeof dp);        
        return solve(cuts,0,cuts.size()-1);
    }
    
    int solve(vector<int> &cuts,int l,int r){
        if(l+1==r) return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int result = INT_MAX;        
        for(int i=l+1;i<=r-1;i++){
            int current = cuts[r]-cuts[l] + solve(cuts,l,i) + solve(cuts,i,r);
            result = min(result,current);
        }
        return dp[l][r] = result;
    }
};