class Solution {
public:
    int dp[1024],visited[1024];
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int mask=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = getCell(i,j,m);
                if(mat[i][j]){
                    mask |= (1<<val);
                }
            }
        }
        memset(dp,-1,sizeof dp);
        memset(visited,false,sizeof visited);
        
        int result = depthFirstSearch(mask,n,m);
        if(result == INT_MAX) result = -1;
        return result;
    }
    
    int depthFirstSearch(int mask,int n,int m){
        if(mask == 0)return 0;

        if(dp[mask]!=-1)
            return dp[mask];
        
        visited[mask]=true;
        int result=INT_MAX;
        
        
        for(int i=0;i<n*m;i++){
            int val = i; 
            int r=val/m;
            int c=val%m;      
            int newMask = mask;
        
            for(int dx:{-1,0,1}){
                for(int dy:{-1,0,1}){
                    int nr = r+dx;
                    int nc = c+dy;
                    if(nr>=0 and nr<n and nc>=0 and nc<m and (dx==0 or dy==0)){ 
                        int newVal = getCell(nr,nc,m);   
                        newMask ^= (1<<newVal);                        
                    }
                }
            }
            
            if(!visited[newMask]){
                int current = depthFirstSearch(newMask,n,m);
                if(current != INT_MAX){
                    current++;
                    result = min(result,current);
                }
            }
        }
        
        visited[mask]=false;
        return dp[mask]=result;
    }
    
    int getCell(int r,int c,int col){
        return r*col+c;
    }
    
};