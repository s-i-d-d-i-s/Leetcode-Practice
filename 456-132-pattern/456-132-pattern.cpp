class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return false;
        
        stack<pair<int,int>> stk;
        vector<int> nextGreater(n,-1),minimum(n);
        
        minimum[0] = nums[0];
        stk.push({nums[0],0});
        
        for(int i=1;i<n;i++){
            minimum[i] = min(minimum[i-1],nums[i]);
            
            while(stk.size()>0 and stk.top().first<nums[i])
                stk.pop();
            
            if(stk.size()>0)
                nextGreater[i]=stk.top().second;
            
            stk.push({nums[i],i});                        
            if(nextGreater[i] != -1){
                int j = nextGreater[i];
                if(j-1>=0 and minimum[j-1]<nums[j] and nums[j]>nums[i] and minimum[j-1]<nums[i])
                        return true;
            }
        }
        return false;
    }
};