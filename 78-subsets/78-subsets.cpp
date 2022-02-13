class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m = powl(2,n);
        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            int mask = i;
            vector<int> subSet;
            for(int j=0;j<n;j++){
                if(mask&1){
                    subSet.push_back(nums[j]);
                }
                mask/=2;
            }
            result.push_back(subSet);
        }
        return result;
    }
};