class Solution {
public:
    int dp[2001][2001];
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof dp);
        return canCross(0,stones,0,stones.size()-1);
    }
    bool canCross(int idx,vector<int> &stones,int k,int dest){
        if(idx == dest) return true;
        
        if(dp[idx][k] != -1)
            return dp[idx][k];
        
        for(int i=idx+1;i<stones.size();i++){
            int jump = stones[i] - stones[idx];
            if(jump == k or jump==(k-1) or jump==(k+1))
                if(canCross(i,stones,jump,dest)) return dp[idx][k] = true;            
        }
        
        return  dp[idx][k] =false;
    }
};