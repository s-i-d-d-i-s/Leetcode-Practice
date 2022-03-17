class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % k !=0 )return false;
        sum/=k;
        int mask=0;
        return canPartition(0,nums,mask,k,0,sum);
    }
    
    bool canPartition(int idx,vector<int> &nums,int mask,int k,int cur,int sumNeeded){
        
        
        
        if(k==1) return true;
        
        if(idx>=nums.size()) return false;
        
        if(cur > sumNeeded) return false;
        
        if(cur == sumNeeded)
            return canPartition(0,nums,mask,k-1,0,sumNeeded);
        
        

        bool isElementVisited = mask & (1<<idx);
        
        if(isElementVisited)
            return canPartition(idx+1,nums,mask,k,cur,sumNeeded);
        
        bool takeThisElement = canPartition(idx+1,nums,mask|(1<<idx),k,cur+nums[idx],sumNeeded);
        bool doNotTakeThisElement = canPartition(idx+1,nums,mask,k,cur,sumNeeded);
        
        return takeThisElement || doNotTakeThisElement;
    }
};