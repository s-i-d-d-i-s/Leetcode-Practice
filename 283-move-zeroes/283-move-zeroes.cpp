class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pt=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                pt++;
                swap(nums[pt],nums[i]);
            }
        }
        return;
    }
};