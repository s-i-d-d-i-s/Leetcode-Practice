class Solution {
public:
    int dp[505][505];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int minDistance(string word1, string word2,int i=0,int j=0) {
        if(j>=word2.length())
            return (word1.length()-i);
        
        if(i>=word1.length())
            return (word2.length()-j);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int result=INT_MAX;        
        
        // Insert
        result = min(result,1+minDistance(word1,word2,i,j+1));
        
        // Delete
        result = min(result,1+minDistance(word1,word2,i+1,j));
        
        // Replace
        result = min(result,1+minDistance(word1,word2,i+1,j+1));
        
        if(word1[i] == word2[j]){
            result = min(result,minDistance(word1,word2,i+1,j+1));
        }
        return dp[i][j]=result;
    }
};