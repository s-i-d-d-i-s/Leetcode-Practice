class Solution {
public:
        bool binarySearchFind(vector<int> &nums,int l,int r,long long key){
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
    vector<vector<int>> twoSum(vector<int> &nums,int l,int r,long long target){
        vector<vector<int>> result;
        for(int i=l;i<=r;i++){
            if(i-1>=l and nums[i-1]==nums[i]){
                continue;
            }
            // x + y = target
            long long neededNumber = target - nums[i];
            if(binarySearchFind(nums,i+1,r,neededNumber)){
                result.push_back({nums[i],(int)neededNumber});
            }
        }
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums,int l,int r,long long neededTarget) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=l;i<=r;i++){
            if(i-1>=l and nums[i]==nums[i-1])continue;
            long long neededTarget2 = neededTarget-nums[i];
            auto solution2Sum = twoSum(nums,i+1,nums.size()-1,neededTarget2);
            for(auto x:solution2Sum){
                result.push_back(x);
                result.back().insert(result.back().begin(),nums[i]);
            }
        }
        return result;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        for(int i=l;i<=r;i++){
            if(i-1>=l and nums[i]==nums[i-1])continue;
            long long neededTarget = target-nums[i];
            auto solution2Sum = threeSum(nums,i+1,nums.size()-1,neededTarget);
            for(auto x:solution2Sum){
                result.push_back(x);
                result.back().insert(result.back().begin(),nums[i]);
            }
        }
        return result;         
    }
};