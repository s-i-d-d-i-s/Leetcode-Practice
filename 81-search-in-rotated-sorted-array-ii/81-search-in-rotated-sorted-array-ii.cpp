class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        int l=0;
        int r=n-1;
        int ll = l;
        int rr = r;
        while(ll<=rr and nums[ll]==nums[rr]){
            if(nums[ll]==target) return true;
            ll++;
            rr--;
        }
        l=ll;
        r=rr;
        while(l<=r){
            if(target>=nums[ll]){
                // Lies in the first array
                while(l<=r){
                    int m = (l+r)/2;
                    if(nums[m]<nums[ll]){
                        r=m-1;                    
                    }else if(target > nums[m]){
                        l=m+1;
                    }else if(target < nums[m]){
                        r=m-1;
                    }else{
                        return true;
                    }
                }
            }else{
                // Lies in the second array
                while(l<=r){
                    int m = (l+r)/2;
                    if(nums[m]>nums[rr]){
                        l=m+1;                    
                    }else if(target > nums[m]){
                        l=m+1;
                    }else if(target < nums[m]){
                        r=m-1;
                    }else{
                        return true;
                    }
                }
            }
        }
        return false;
    }
};