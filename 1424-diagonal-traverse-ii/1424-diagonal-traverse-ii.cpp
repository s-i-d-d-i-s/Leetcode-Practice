class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> hMap;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                int diagSum = (i+j);
                hMap[diagSum].push_back(nums[i][j]);
            }
        }        
        vector<int> result;
        for(auto x:hMap){
            reverse(hMap[x.first].begin(),hMap[x.first].end());
            for(int y:hMap[x.first]){
                result.push_back(y);
            }
        }
        return result;
    }
};