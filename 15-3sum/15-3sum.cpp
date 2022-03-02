class Solution {
public:
    bool binarySearchFind(vector<int> &nums,int l,int r,int key){
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]>key){
                r=m-1;
            }else if(nums[m]<key){
                l=m+1;
            }else{
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> twoSum(vector<int> &nums,int l,int r,int target){
        vector<vector<int>> result;
        for(int i=l;i<=r;i++){
            if(i-1>=l and nums[i-1]==nums[i]){
                continue;
            }
            // x + y = target
            int neededNumber = target - nums[i];
            if(binarySearchFind(nums,i+1,r,neededNumber)){
                result.push_back({nums[i],neededNumber});
            }
        }
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // -1 -1 0 1 2 4
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i-1>=0 and nums[i]==nums[i-1])continue;
            
            //  y + z = -x
            int neededTarget = -nums[i];
            auto solution2Sum = twoSum(nums,i+1,nums.size()-1,neededTarget);
            for(auto x:solution2Sum){
                result.push_back(x);
                result.back().insert(result.back().begin(),nums[i]);
            }
        }
        return result;
    }
};