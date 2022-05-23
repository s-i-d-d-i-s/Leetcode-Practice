class Solution {
public:
    int dp[601][101][101];
    int solve(int idx,vector<string>& strs,int c0,int c1, int m, int n){
        if(idx>=strs.size())
            return 0;
        
        if(dp[idx][c0][c1]!=-1)
            return dp[idx][c0][c1];
        
        int res=solve(idx+1,strs,c0,c1,m,n);
        int cur_c1=count(strs[idx].begin(),strs[idx].end(),'1');
        int cur_c0=count(strs[idx].begin(),strs[idx].end(),'0');
        
        if(c0+cur_c0<=m and c1+cur_c1<=n){
            res=max(res,1+solve(idx+1,strs,c0+cur_c0,c1+cur_c1,m,n));
        }
        return dp[idx][c0][c1]=res;
    }
    int findMaxForm(vector<string>& strs, int n, int m) {
        memset(dp,-1,sizeof dp);
        int res=solve(0,strs,0,0,n,m);
        return res;
    }
};