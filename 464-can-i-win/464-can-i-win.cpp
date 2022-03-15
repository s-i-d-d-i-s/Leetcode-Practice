class Solution {
public:
    short dp[1048576+5][2];
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        memset(dp,-1,sizeof dp);
        int maxSum = (maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(maxSum < desiredTotal)return false;
        return canPlayerWin(0,desiredTotal,maxChoosableInteger,0);
    }
    bool canPlayerWin(int mask,int desiredTotal,int maxChoosableInteger,int player){
        int cur=0;
        for(int i=1;i<=maxChoosableInteger;i++){
            int bit = (1<<(i-1));
            if(mask & bit){
                cur+=i;
            }
        }
        if(cur>=desiredTotal){
            return true;
        }
        if(dp[mask][player]!=-1){
            return dp[mask][player];
        }        
        for(int i=1;i<=maxChoosableInteger;i++){
            int bit = (1<<(i-1));
            if(mask & bit){
                
            }else{
                if(cur+i>=desiredTotal){
                    return dp[mask][player]=true;
                }
                if(!canPlayerWin(mask|bit,desiredTotal,maxChoosableInteger,player^1)){
                    return dp[mask][player]=true;
                }
            }
        }
        return dp[mask][player]=false;
    }
};