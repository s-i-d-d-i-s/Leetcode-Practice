class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        unordered_map<int,vector<int>> index;
        for(int i=0;i<=r;i++){
            index[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum<target){
                l++;
            }else if(sum>target){
                r--;
            }else{
                int l1=index[nums[l]].back();
                index[nums[l]].pop_back();
                int l2=index[nums[r]].back();
                return {l1,l2};
            }
        }
        return {-1,1};
    }
};