class Solution {
public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int numDistinct(string &s, string &t,int i=0,int j=0) {
        if(j>=t.length())
            return 1;
        if(i>=s.length())
            return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j]=numDistinct(s,t,i+1,j) + numDistinct(s,t,i+1,j+1);
        }
        return dp[i][j]=numDistinct(s,t,i+1,j);
    }
};