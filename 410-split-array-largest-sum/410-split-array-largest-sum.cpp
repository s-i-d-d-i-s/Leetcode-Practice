class Solution {
public:
    int dp[1001][1001];
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums,m);
    }
    
    int solve(int idx,vector<int> &nums,int m){
        if(idx>=nums.size()){
            if(m==1) return 0;
            return INT_MAX;
        }
        if(dp[idx][m] != -1){
            return dp[idx][m];
        }
        if(m==1){
            int result = solve(idx+1,nums,m);
            if(result == INT_MAX)
                return dp[idx][m]=result;
            result += nums[idx];
            return dp[idx][m]=result;
        }
        int result=INT_MAX;
        int prefix=0;
        for(int i=idx;i<nums.size()-m+1;i++){
            prefix+=nums[i];
            int subProblem = solve(i+1,nums,m-1);
            result = min(result,max(prefix,subProblem));            
        }
        return dp[idx][m]=result;
    }
};