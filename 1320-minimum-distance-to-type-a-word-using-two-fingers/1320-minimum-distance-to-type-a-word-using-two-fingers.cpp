class Solution {
public:
    int dp[26][26][305];
    int minimumDistance(string word) {
        int result=word.length()*12 + 1;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                result = min(result,solve(i,j,0,word));
            }
        }
        return result;
    }
    
    int solve(int p1,int p2,int idx,string &word){
        if(idx>=word.length()) return 0;
        
        if(dp[p1][p2][idx] != -1){
            return dp[p1][p2][idx];
        }
        int r1 = p1/6;
        int c1 = p1%6;
        
        int r2 = p2/6;
        int c2 = p2%6;
        
        int wordIndex = word[idx]-'A';
        int tr = wordIndex/6;
        int tc = wordIndex%6;
        
        // Type current word with p1
        int subProblem1 = distance(r1,c1,tr,tc) + solve(wordIndex,p2,idx+1,word);
        
        // Type current word with p2
        int subProblem2 = distance(r2,c2,tr,tc) + solve(p1,wordIndex,idx+1,word);
        
        return dp[p1][p2][idx] = min(subProblem1,subProblem2);
    }
    
    int distance(int r1,int c1,int r2,int c2){
        return abs(r1-r2) + abs(c1-c2);
    }
};