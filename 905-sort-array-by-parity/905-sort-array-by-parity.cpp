class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pt=-1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0){
                pt++;
                swap(nums[pt],nums[i]);
            }
        }
        return nums;
    }
};