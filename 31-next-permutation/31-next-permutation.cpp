class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPoint=i;
                break;
            }
        }
        if(breakPoint==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int breakPoint2=-1;
        for(int i=n-1;i>=breakPoint;i--){
            if(nums[i]>nums[breakPoint]){
                breakPoint2=i;
                break;
            }
        }
        swap(nums[breakPoint],nums[breakPoint2]);
        reverse(nums.begin()+breakPoint+1,nums.end());
        
    }
};