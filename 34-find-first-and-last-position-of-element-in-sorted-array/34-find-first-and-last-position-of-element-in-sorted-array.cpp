class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)return {-1,-1};
        int start=n;
        int end=-1;
        int l,r;
        l=0;
        r=n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]>target){
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }else{
                start=min(start,m);
                r=m-1;
            }
        }
        l=0;
        r=n-1;
        // start
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]>target){
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }else{
                end=max(end,m);
                l=m+1;
            }
        }
        
        if(start == n){
            start=-1;
            end=-1;
        }
        
        return {start,end};
    }
};