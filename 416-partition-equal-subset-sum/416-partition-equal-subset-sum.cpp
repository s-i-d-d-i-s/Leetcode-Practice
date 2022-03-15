class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0LL);
        if(totalSum & 1)return false;
        
        int sum = totalSum / 2;
        memset(dp,-1,sizeof dp);
        return findSubset(0,nums,sum);
    }
    
    bool findSubset(int idx,vector<int> &nums,int target){
        if(idx>=nums.size()){
            return target == 0;
        }
        if(target < 0)return false;
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        return dp[idx][target]=findSubset(idx+1,nums,target) || findSubset(idx+1,nums,target-nums[idx]);
    }
};