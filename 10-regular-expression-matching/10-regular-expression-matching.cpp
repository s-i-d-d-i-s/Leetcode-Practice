class Solution {
public:
    int dp[35][35];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    bool isMatch(string &s, string &p,int i=0,int j=0) {
        
        if(j>=p.length())
            return i>=s.length();
        
        if(dp[i][j] != -1)
            return dp[i][j];         
        
        bool result=false;
        
        bool currentMatch = i<s.length() and (s[i]==p[j] or p[j]=='.');
        bool astrixAhead = j+1<p.length() and p[j+1]=='*';
        if(astrixAhead){            
            result |= isMatch(s,p,i,j+2);            
            if(currentMatch)
                result |= isMatch(s,p,i+1,j);
            
        }        
        
        if(currentMatch)
            result |= isMatch(s,p,i+1,j+1);
        
        return dp[i][j]=result;
    }
    
};