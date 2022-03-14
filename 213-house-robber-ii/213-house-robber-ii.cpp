class Solution {
public:
    int rob(vector<int>& nums) {
        int result = robUtil(nums);
        reverse(nums.begin(),nums.end());
        result = max(result,robUtil(nums));
        return result;
    }
    int robUtil(vector<int>& nums) {
        int n = nums.size();
        if(n<=3){
            return *max_element(nums.begin(),nums.end());
        }
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            if((i==n-1)){
                dp[i]=dp[i-1];
                continue;
            }
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};