class Solution {
public:
    int dp[101][101][202];
    
    int catMouseGame(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof dp);
        return winner(1,2,graph);
    }
    /*
        turn = 0 : mouse
        turn = 1 : cat
    */
    int winner(int mouse,int cat,vector<vector<int>>& graph,int turn=0){
        
        if(turn>3*graph.size())
            return 0;
        
        if(mouse == 0)  return 1;
        if(cat == mouse) return 2;
        
        
        if(dp[mouse][cat][turn] != -1)
            return dp[mouse][cat][turn];
                
        if(turn%2==0){            
            bool canDraw=0;
            for(int x:graph[mouse]){
                int next = winner(x,cat,graph,turn+1);
                if(next == 1) return dp[mouse][cat][turn]=1;                
                if(next == 0) canDraw = 1;                
            }
            if(canDraw) return dp[mouse][cat][turn]=0;
            return dp[mouse][cat][turn]=2;
        }else{            
            bool canDraw=0;
            for(int x:graph[cat]){
                if(x==0)continue;
                int next = winner(mouse,x,graph,turn+1);
                if(next == 2) return dp[mouse][cat][turn]=2;
                if(next == 0) canDraw = 1;                
            }
            if(canDraw) return dp[mouse][cat][turn]=0;
            return dp[mouse][cat][turn]=1;
        }
        return 0;
    }
};