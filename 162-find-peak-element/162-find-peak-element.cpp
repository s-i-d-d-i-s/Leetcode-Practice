class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        
        while(r-l>=3){
            int m1 = l+(r-l)/3;
            int m2 = r-(r-l)/3;
            if(nums[m1] < nums[m2]){
                l=m1+1;
            }else{
                r=m2-1;
            }
        }
        for(int i=l;i<=r;i++){
            long long left=i-1>=0?nums[i-1]:LONG_MIN;
            long long right=i+1<nums.size()?nums[i+1]:LONG_MIN;
            if(nums[i]>left and nums[i]>right) return i;
        }
        //cout << l << " " << r << endl;
        return -1;
    }
};