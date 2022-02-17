class Solution {
public:
    set<vector<int>> res;
    void solve(int idx,vector<int> &nums,int last,vector<int> &cur){
        if(idx>=nums.size()){
            if(cur.size()>=2)
                res.insert(cur);
            return;
        }
        if(nums[idx]>=last){
            cur.push_back(nums[idx]);
            solve(idx+1,nums,max(nums[idx],last),cur);
            cur.pop_back();
        }
        solve(idx+1,nums,last,cur);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> current;
        solve(0,nums,INT_MIN,current);
        vector<vector<int>> result(res.begin(),res.end());
        return result;
    }
};