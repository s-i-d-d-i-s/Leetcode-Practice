class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res=0;
        for(auto x:accounts){
            res = max(res,(int)accumulate(x.begin(),x.end(),0LL));
        }
        return res;
    }
};