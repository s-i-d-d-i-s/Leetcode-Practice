class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(robUtil(nums,0,n-2),robUtil(nums,1,n-1));
    }
    int robUtil(vector<int>& nums,int l,int r) {
        int n = nums.size();
        if(l==r) return nums[l];
        
        vector<int> dp(n);
        dp[l]=nums[l];
        dp[l+1]=max(nums[l],nums[l+1]);
        
        for(int i=l+2;i<=r;i++)
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        return dp[r];
    }
};