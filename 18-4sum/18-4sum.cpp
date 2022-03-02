class Solution {
public:
    vector<vector<int>> nMinus1Sum(vector<int> &nums,int l,int r,int target,int n){
        vector<vector<int>> result;
        if(n==2){
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
        }else{
            for(int i=l;i<=r;i++){
                if(i-1>=l and nums[i]==nums[i-1])continue;
                long long neededTarget = target-nums[i];
                auto solutionNMinus1Sum = nMinus1Sum(nums,i+1,nums.size()-1,neededTarget,n-1);
                for(auto x:solutionNMinus1Sum){
                    result.push_back(x);
                    result.back().push_back(nums[i]);
                }
            }
        }
        return result;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        return nMinus1Sum(nums,0,nums.size()-1,target,4);         
    }
};