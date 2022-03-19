class Solution {
public:
    int getSubarrays(int l,int r){
        if(l>r)return 0;
        int len = r-l+1;
        return len;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int window = 1;
        int result=0;
        
        while(j<n){
            window *= nums[j];
            while(i<=j and window >=k){
                window /= nums[i];
                i++;
            }
            result += getSubarrays(i,j);
            j++;
        }
        return result;
    }
};