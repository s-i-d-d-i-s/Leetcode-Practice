class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int result=0;
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
            int next = arr[i]+difference;
            if(dp.find(next) != dp.end()){
                dp[arr[i]] = 1+dp[next];
            }else{
                dp[arr[i]] = 1;
            }
            result = max(dp[arr[i]],result);
        }
        return result;
    }
};