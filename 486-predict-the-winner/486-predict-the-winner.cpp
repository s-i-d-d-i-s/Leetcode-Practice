class Solution {
public:
    int dp[21][21][2];
    
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int total = accumulate(nums.begin(),nums.end(),0);    
        int maxScoreA = maxScoreByA(nums,0,nums.size()-1,true);
        int maxScoreB = total - maxScoreA;
        return maxScoreA >= maxScoreB;
    }
    int maxScoreByA(vector<int>& nums,int l,int r,bool isTurnForA){
        if(l>r)
            return 0;
        
        if(dp[l][r][isTurnForA] != -1){
            return dp[l][r][isTurnForA];
        }
        // Choose from the left
        int outcome_1 = nums[l]*isTurnForA + maxScoreByA(nums,l+1,r,isTurnForA^1);
        int outcome_2 = nums[r]*isTurnForA + maxScoreByA(nums,l,r-1,isTurnForA^1);
        
        if(isTurnForA)
            return dp[l][r][isTurnForA]=max(outcome_1,outcome_2);
        
        return dp[l][r][isTurnForA]=min(outcome_1,outcome_2);
    }
};