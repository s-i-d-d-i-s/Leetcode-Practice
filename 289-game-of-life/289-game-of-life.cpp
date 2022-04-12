class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int neighbors = getNeighbors(board,i,j);
                if(board[i][j]){
                    // Live
                    if(neighbors==2 or neighbors==3){
                        board[i][j]+=2;
                    }
                }else{
                    // Dead
                    if(neighbors==3){
                        board[i][j]+=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]/=2;
            }
        }
    }
    
    int getNeighbors(vector<vector<int>> &board,int x, int y){
        int result=0;
        int n = board.size();
        int m = board[0].size();
        
        for(int dx:{-1,0,1}){
            for(int dy:{-1,0,1}){
                int nr = x + dx;
                int nc = y + dy;
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    result += (board[nr][nc]&1);
                }
            }
        }
        return result - board[x][y];
    }
};