class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> stk;
        stk.push_back({nums[0],0});
        int result=0;
        for(int i=1;i<nums.size();i++){            
            if(nums[i]<stk.back().first){
                stk.push_back({nums[i],i});
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(stk.size()>0 and stk.back().first<=nums[i]){
                result = max(result,i-stk.back().second);
                stk.pop_back();
            }
        }
        return result;
    }
    
};