class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(20000,0);
        for(int x:nums){
            freq[x]++;
        }
        vector<int> dp(freq.size());
        dp[0]=0;
        dp[1]=freq[0];
        dp[2]=max(freq[1]+dp[0],dp[1]);
        for(int i=3;i<20000;i++){
            dp[i] = max((i-1)*freq[i-1]+dp[i-2],dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};