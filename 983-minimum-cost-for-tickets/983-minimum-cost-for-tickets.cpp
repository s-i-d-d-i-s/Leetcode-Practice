class Solution {
public:
    int dp[405][405];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs,int idx=0,int passExpiry=0) {
        if(idx>=days.size()) return 0;
        if(dp[idx][passExpiry] != -1){
            return dp[idx][passExpiry];
        }
        if(days[idx] <= passExpiry){
            int buyNothing = mincostTickets(days,costs,idx+1,passExpiry);
            
            int buy1day  = costs[0] + mincostTickets(days,costs,idx+1, min( max( passExpiry,days[idx] ),400) );
            int buy7day  = costs[1] + mincostTickets(days,costs,idx+1, min( max( passExpiry,days[idx] + 6),400) );
            int buy30day = costs[2] + mincostTickets(days,costs,idx+1, min( max( passExpiry,days[idx] + 29),400) );
            
            return dp[idx][passExpiry] = min({buyNothing,buy1day,buy7day,buy30day});
        }else{
            int buy1day  = costs[0] + mincostTickets(days,costs,idx+1, min( max( passExpiry,days[idx] ),400) );
            int buy7day  = costs[1] + mincostTickets(days,costs,idx+1, min( max( passExpiry,days[idx] + 6),400) );
            int buy30day = costs[2] + mincostTickets(days,costs,idx+1, min( max( passExpiry,days[idx] + 29),400) );
            return dp[idx][passExpiry] = min({buy1day,buy7day,buy30day});
        }
        
        return 0;
    }
};