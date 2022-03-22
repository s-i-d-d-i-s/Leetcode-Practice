class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3)return 0;
        sort(nums.begin(),nums.end());
        return min({
            getMin(0,3,nums),
            getMin(1,2,nums),
            getMin(2,1,nums),
            getMin(3,0,nums)
        });
    }
    
    int getMin(int removeFromFront,int removeFromBack,vector<int>& nums){
        int l=0;
        int r=nums.size()-1;
        while(removeFromFront-->0) l++;
        while(removeFromBack-->0) r--;
        return nums[r]-nums[l];
    }
};