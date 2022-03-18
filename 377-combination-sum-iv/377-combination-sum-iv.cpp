class Solution {
public:
    
    int dp[1000+1];
    int solve(vector<int>& cand,int currentSum,int target){             
        if(currentSum > target)
            return 0;
        if(currentSum==target){
            return 1;
        }
        if(dp[currentSum] != -1){
            return dp[currentSum];
        }
        int result=0;
        for(int x:cand){
            result += solve(cand,currentSum+x,target);
        }        
        return dp[currentSum]=result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof dp);
        int result = solve(nums,0,target);
        return result;
    }
};