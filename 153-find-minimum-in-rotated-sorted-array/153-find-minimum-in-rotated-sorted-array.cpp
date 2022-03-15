class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums.back()) return nums[0];
        int n = nums.size();
        int l=0;
        int r=n-1;
        int result = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            result = min(result,nums[m]);
            if(nums[m]>=nums[0]){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return result;
    }
};