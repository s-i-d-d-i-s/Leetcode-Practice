class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <=1000 and depthFirstSearch(i,nums))return true;
        }
        return false;
    }
    bool depthFirstSearch(int source,vector<int> &nums){
        if(nums[source] == 1001)return true;
        if(nums[source] == 1002)return false;
        
        int next = getNextIndex(source,nums);
        if(source == next or nums[source]*nums[next]<0 and nums[next]<=1000){
            nums[source]=1002;
            return false;
        }
        
        nums[source]=1001;         
        if(depthFirstSearch(next,nums))return true;        
        nums[source]=1002;
        return false;
    }
    
    int getNextIndex(int source,vector<int> &nums){
        int n = nums.size();
        int next= source + nums[source];
        if(next >=0 ){
            next %=n;
        }else{
            next+=n*1000;
            next%=n;
        }
        return next;
    }
};