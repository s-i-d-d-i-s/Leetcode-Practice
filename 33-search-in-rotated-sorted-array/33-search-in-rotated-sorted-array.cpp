class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l=0;
        int r=n-1;
        
        if(target>=nums[0]){
            // Lies in the first array
            while(l<=r){
                int m = (l+r)/2;
                if(nums[m]<nums[0]){
                    r=m-1;                    
                }else if(target > nums[m]){
                    l=m+1;
                }else if(target < nums[m]){
                    r=m-1;
                }else{
                    return m;
                }
            }
        }else{
            // Lies in the second array
            while(l<=r){
                int m = (l+r)/2;
                if(nums[m]>nums[n-1]){
                    l=m+1;                    
                }else if(target > nums[m]){
                    l=m+1;
                }else if(target < nums[m]){
                    r=m-1;
                }else{
                    return m;
                }
            }
        }
        return -1;
    }
};