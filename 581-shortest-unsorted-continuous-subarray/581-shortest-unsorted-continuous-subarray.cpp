class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        stack<int> stk;
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (stk.size()>0 && nums[stk.top()] > nums[i]){
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        while(stk.size()>0)
            stk.pop();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (stk.size()>0 && nums[stk.top()] < nums[i]){
                r = max(r, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return r - l > 0 ? r - l + 1 : 0;
    }
};