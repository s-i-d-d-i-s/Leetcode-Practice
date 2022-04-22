class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total-nums[0] == 0) return 0;
        int sum = 0;
        for(int i=0;i<(int)nums.size()-1;i++){
            sum += nums[i];
            total -= nums[i];
            if(sum == total-nums[i+1]) return i+1;
        }
        return -1;
    }
};