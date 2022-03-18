class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        stack<int> stk;
        for(int i=n-1;i>=0;i--)
            stk.push(nums[i]);

        for(int i=n-1;i>=0;i--){
            while(stk.size()>0 and stk.top() <= nums[i]){
                stk.pop();
            }
            if(stk.size()>0)
                dp[i] = stk.top();
            
            stk.push(nums[i]);
        }
        return dp;
    }
};