class Solution {
public:
    int dp[205][205];
    
    Solution(){
        memset(dp,-1,sizeof dp);        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        int result = calculateMinimumHP(dungeon,0,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return result;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon,int r,int c) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int healthToSurviveHere = dungeon[r][c] <= 0 ? -dungeon[r][c] + 1 : 1;
        
        if(r==n-1 and c==m-1){
            return healthToSurviveHere;
        }
        
        if(r==n-1){
            int right = calculateMinimumHP(dungeon,r,c+1);
            int extraHealth = right-1;
            int enoughHealth = healthToSurviveHere + extraHealth; 
            int helpOffered = dungeon[r][c]>0? dungeon[r][c]:0;            
            return dp[r][c] = max(1,enoughHealth-helpOffered);
        }
        
        if(c==m-1){
            int down = calculateMinimumHP(dungeon,r+1,c);
            int extraHealth = down-1;
            int enoughHealth = healthToSurviveHere + extraHealth; 
            int helpOffered = dungeon[r][c]>0? dungeon[r][c]:0;            
            return dp[r][c] = max(1,enoughHealth-helpOffered);
        }
        
        int helpOffered = dungeon[r][c]>0? dungeon[r][c]:0;            
        
        
        int right = calculateMinimumHP(dungeon,r,c+1);
        int extraHealth = right-1;
        int enoughHealthRight = healthToSurviveHere + extraHealth;
        enoughHealthRight -= helpOffered;
        
        int down = calculateMinimumHP(dungeon,r+1,c);
        extraHealth = down-1;
        int enoughHealthDown = healthToSurviveHere + extraHealth;
        enoughHealthDown -= helpOffered;
        
        return dp[r][c] = max(1,min(enoughHealthDown,enoughHealthRight));
    }
};