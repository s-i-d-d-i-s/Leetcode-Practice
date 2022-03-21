class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> stk;
        stk.push_back({nums[0],0});
        int result=0;
        for(int i=1;i<nums.size();i++){
            int current_width = getWidth(stk,nums[i],i);
            if(nums[i]<stk.back().first){
                stk.push_back({nums[i],i});
            }
            result = max(result,current_width);
        }
        return result;
    }
    int getWidth(vector<pair<int,int>> &stk,int target,int i){
        if(stk.back().first>target) return INT_MIN;
        int l=0;
        int r=stk.size();
        int result = stk.back().second;
        while(l<=r){
            int m = (l+r)/2;
            if(stk[m].first<=target){
                result = min(result,stk[m].second);
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return i-result;
    }
};