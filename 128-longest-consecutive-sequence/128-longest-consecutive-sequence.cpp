class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int res=1;
        int count=1;
        int last=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==(last+1)){
                count++;
            }else if(nums[i]>(last+1)){
                count=1;
            }else{
                
            }
            last=nums[i];
            res = max(res,count);
        }
        return res;
    }
};