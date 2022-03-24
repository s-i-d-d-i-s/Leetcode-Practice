class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n= nums.size();
        vector<int> result(n);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i+=2){
            result[i] = nums.back();
            nums.pop_back();
        }
        for(int i=0;i<n;i+=2){
            result[i] = nums.back();
            nums.pop_back();
        }
        nums=result;
    }
};