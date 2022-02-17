class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx,vector<int>& cand,vector<int>& current,int currentSum,int target){
        if(idx>=cand.size()){
            if(currentSum==target)
                res.push_back(current);
            
            return;
        }
        
        if(currentSum > target)
            return;
        solve(idx+1,cand,current,currentSum,target);
        for(int i=0;i<=150;i++){
            currentSum+=cand[idx];
            current.push_back(cand[idx]);
            solve(idx+1,cand,current,currentSum,target);
        }
        for(int i=0;i<=150;i++){
            currentSum-=cand[idx];
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        solve(0,candidates,cur,0,target);
        return res;
    }
};