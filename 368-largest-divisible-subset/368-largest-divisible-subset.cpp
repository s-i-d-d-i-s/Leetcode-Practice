class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n);
        sort(nums.begin(),nums.end());
        
        dp[0]={1,-1};
        int maximumLength=1;
        for(int i=1;i<n;i++){
            int maxi=0;
            int idx=-1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j] == 0){
                    if(dp[j].first > maxi){
                        maxi=dp[j].first;
                        idx=j;
                    }
                }
            }
            dp[i]={maxi+1,idx};
            maximumLength = max(maximumLength,maxi+1);
        }
        for(int i=0;i<n;i++){
            if(dp[i].first==maximumLength){
                vector<int> result;
                int start = i;
                while(start != -1){
                    result.push_back(nums[start]);
                    start=dp[start].second;
                }
                return result;
            }
        }
        return {};
    }
};