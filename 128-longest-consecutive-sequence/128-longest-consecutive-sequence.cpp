class Solution {
public:
    unordered_map<int,int> hMap,dp;
    int solve(int start,vector<int> &nums){
        if(hMap.find(start)==hMap.end()) return 0;
        if(dp.find(start)!=dp.end()) return dp[start];
        return dp[start]=1+solve(start+1,nums);
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;

        for(int x:nums) hMap[x]=1;
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            res = max(res,solve(nums[i],nums));
        }
        return res;
    }
};