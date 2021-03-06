class Solution {
public:
    int dp[205][205];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    bool isInterleave(string &s1, string s2, string s3,int i=0,int j=0) {
        int k = (i+j);
        if(k>=s3.length()){
            return i>=s1.length() and j>=s2.length();
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool result = false;
        if(s1[i] == s3[k]){
            result |= isInterleave(s1,s2,s3,i+1,j);
        }
        
        if(s2[j] == s3[k]){
            result |= isInterleave(s1,s2,s3,i,j+1);
        }
        
        return dp[i][j]=result;
    }
};