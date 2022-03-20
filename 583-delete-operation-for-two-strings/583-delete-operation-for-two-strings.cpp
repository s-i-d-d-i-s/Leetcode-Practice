class Solution {
public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int longestCommonSubsequence(string &text1, string &text2,int i=0,int j=0) {
        if(i>=text1.length() or j>=text2.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return dp[i][j] = 1+longestCommonSubsequence(text1,text2,i+1,j+1);
        return dp[i][j]=max(longestCommonSubsequence(text1,text2,i+1,j),longestCommonSubsequence(text1,text2,i,j+1));
    }
    
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1,word2);
        return word1.length() + word2.length() - 2*lcs;
    }
};