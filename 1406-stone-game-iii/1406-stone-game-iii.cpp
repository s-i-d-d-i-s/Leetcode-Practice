class Solution {
public:
    int dp[50005][2];
    
    string stoneGameIII(vector<int>& stoneValue) {
        int totalScore = accumulate(stoneValue.begin(),stoneValue.end(),0);
        memset(dp,-1,sizeof dp);
        int scoreA = maxScoreA(0,stoneValue);
        int scoreB = totalScore-scoreA;
        if(scoreA>scoreB) return "Alice";
        if(scoreB>scoreA) return "Bob";
        return "Tie";
    }
    
    int maxScoreA(int idx,vector<int>& stoneValue,bool isA=true) {
        int n = stoneValue.size();
        if(idx>=n) return 0;
        if(dp[idx][isA] != -1){
            return dp[idx][isA];
        }
        if(isA){
            
            // take 1
            int result=stoneValue[idx]+maxScoreA(idx+1,stoneValue,!isA);
            
            // take 2
            if(idx+1<n)
                result = max(result,stoneValue[idx]+stoneValue[idx+1]+maxScoreA(idx+2,stoneValue,!isA));            
            
            // take 3
            if(idx+2<n)
                result = max(result,stoneValue[idx]+stoneValue[idx+1]+stoneValue[idx+2]+maxScoreA(idx+3,stoneValue,!isA));
            return dp[idx][isA]=result;
        }else{
            
            // take 1
            int result=maxScoreA(idx+1,stoneValue,!isA);
            
            // take 2
            if(idx+1<n)
                result = min(result,maxScoreA(idx+2,stoneValue,!isA));            
            
            // take 3
            if(idx+2<n)
                result = min(result,maxScoreA(idx+3,stoneValue,!isA));
            
            return dp[idx][isA]=result;
        }
        
        return 0;
    }
};