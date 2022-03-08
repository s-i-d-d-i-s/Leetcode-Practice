class Solution {
public:
    int dp[1001][1001];
    bool isPalin(string &a,int l,int r){
        if(l>=r)return true;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        if(a[l] == a[r] and isPalin(a,l+1,r-1))
            return dp[l][r]=true;
        
        return dp[l][r]=false;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof dp);
        isPalin(s,0,s.length()-1);
        int maxLength=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalin(s,i,j)){
                    maxLength = max(maxLength,j-i+1);
                }
            }
        }
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalin(s,i,j) and (j-i+1)==maxLength){
                    string result="";
                    for(int k=i;k<=j;k++)result.push_back(s[k]);
                    return result;
                }
            }
        }
        return "";
    }    
};