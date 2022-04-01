class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int result=0;
        int r=0;
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi = max(maxi,i+nums[i]);
            if(i>=r){
                r=maxi;
                result++;
            }
        }
        return result;
    }
};