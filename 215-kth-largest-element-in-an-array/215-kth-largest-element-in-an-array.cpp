class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums,0,n-1,n-k+1);
    }
    
    int quickSelect(vector<int>& nums, int l,int r,int k){
        int pivot = nums[r];
        int partitionIndex = paritionElements(nums,l,r,pivot);
        if(partitionIndex == k - 1) return nums[partitionIndex];
        if(partitionIndex < k - 1) return quickSelect(nums,partitionIndex+1,r,k);
        return quickSelect(nums,l,partitionIndex-1,k);
    }
    
    int paritionElements(vector<int>& nums, int l,int r,int pivot){
        int pt=l-1;
        for(int i=l;i<=r;i++){
            if(nums[i]<=pivot){
                pt++;
                swap(nums[pt],nums[i]);
            }
        }
        return pt;
    }
};