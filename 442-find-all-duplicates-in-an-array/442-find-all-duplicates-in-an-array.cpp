class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int val = abs(nums[i]);
            bool isVisited = nums[abs(nums[i])-1] < 0;
            
            if(isVisited)
                result.push_back(val);
            
            if(nums[val-1]>0)
                nums[val-1]*=-1;
        }
        return result;
    }
};