class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> nums2=nums;
        int result=0;
        for(int i=0;i<=32;i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                count += abs(nums[j]%2!=0);
                nums[j]/=2;
            }
            if(count%3 == 1)
                result += (1<<i);            
        }        
        if(!isSingle(nums2,result))
            result *= -1;        
        return result;
    }
    bool isSingle(vector<int> &nums,int x){
        int count=0;
        for(int y:nums) count+=(x==y);
        return count==1;
    }
};