class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &nums,int l,int r,int target){
        vector<vector<int>> result;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum > target){
                r--;
            }else if(sum < target){
                l++;
            }else{
                int num1 = nums[l];
                int num2 = nums[r];
                result.push_back({num1,num2});
                while(l<=r and nums[l] == num1){
                    l++;
                }
                while(r>=l and nums[r] == num2){
                    r--;
                }
            }
        }
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i-1>=0 and nums[i]==nums[i-1])continue;
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