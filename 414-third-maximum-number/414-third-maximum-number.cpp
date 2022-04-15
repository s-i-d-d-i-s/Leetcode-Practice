class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = findMaxLessThan(nums,LONG_MAX);
        long max2 = findMaxLessThan(nums,max1);
        long max3 = findMaxLessThan(nums,max2);
        if(max3 == LONG_MIN) return max1;
        return max3;
    }
    long findMaxLessThan(vector<int> &nums,long target){
        long result=LONG_MIN;
        for(long x:nums){
            if(x<target){
                result = max(result,x);
            }
        }
        return result;
    }
    
};