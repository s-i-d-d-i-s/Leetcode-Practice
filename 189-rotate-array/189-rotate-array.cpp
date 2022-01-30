class Solution {
public: 
    void rev(vector<int>& nums,int l,int r){
        while(l<r) swap(nums[l++],nums[r--]);
    }
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k==0)return;
        rev(nums,0,nums.size()-1);
        rev(nums,0,k-1);
        rev(nums,k,nums.size()-1);
    }
};
