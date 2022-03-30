class Solution {
public:
    int dp[2001][2001];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    bool isMatch(string &s, string &p,int i=0,int j=0) {
        
        if(j>=p.length())
            return i>=s.length();
        
        if(i>=s.length()){
            if(p[j]=='*') return dp[i][j]=isMatch(s,p,i,j+1);
            return dp[i][j]=false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];         
        
        bool result=false;
        
        if(p[j]=='?')
            result |= isMatch(s,p,i+1,j+1);
        
        if(p[j]=='*')
            result |= isMatch(s,p,i+1,j+1) or isMatch(s,p,i+1,j) or isMatch(s,p,i,j+1);
        
        if(p[j] == s[i])
            result |= isMatch(s,p,i+1,j+1);
        
        return dp[i][j]=result;
    }
};