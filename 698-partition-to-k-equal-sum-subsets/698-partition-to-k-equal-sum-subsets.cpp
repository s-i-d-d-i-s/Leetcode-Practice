class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % k !=0 )return false;
        sum/=k;
        int mask=0;
        //sort(nums.begin(),nums.end(),greater<int>());
        return generate(0,nums,mask,k,0,sum);
    }
    
    bool generate(int idx,vector<int> &nums,int mask,int k,int cur,int sumNeeded){
        
        if(k==1)
            return true;
        
        if(idx>=nums.size())
            return false;
        
        if(cur == sumNeeded)
            return generate(0,nums,mask,k-1,0,sumNeeded);

        
        if( !(mask & (1<<idx)) and cur+nums[idx] <= sumNeeded){
            if(generate(idx+1,nums,mask|(1<<idx),k,cur+nums[idx],sumNeeded))
                return true;
        }
        return generate(idx+1,nums,mask,k,cur,sumNeeded);
    }
};