class Solution {
public:
    vector<vector<int>> result;
    void generatePermutation(int idx,int n,vector<int> &visit,vector<int> &currentPermutation,vector<int> &nums){
        if(idx>=n){
            vector<int> solution;
            for(int x:currentPermutation){
                solution.push_back(nums[x]);
            }
            result.push_back(solution);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!visit[i]){
                visit[i]=1;
                currentPermutation.push_back(i);
                generatePermutation(idx+1,n,visit,currentPermutation,nums);
                currentPermutation.pop_back();
                visit[i]=0;
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visit(10,0);
        vector<int> currentPermutation;
        generatePermutation(0,nums.size(),visit,currentPermutation,nums);
        return result;
    }
};