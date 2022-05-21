class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = -1;
        int r = n;
        int pt=0;
        while(pt < r){
            if(nums[pt] == 0){
                l++;
                swap(nums[l],nums[pt]);
                pt++;
            }else if(nums[pt] == 1){
                pt++;
            }else{
                r--;
                swap(nums[r],nums[pt]);
            }
        }
    }
};