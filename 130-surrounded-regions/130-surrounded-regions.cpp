class Solution {
public:
    
    void dfs(int x,int y,vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        
        if(x<0 or x>=n or y<0 or y>=m or board[x][y] != 'O') return ;
        
        if(board[x][y]=='X') return;
        
        board[x][y]='#';
        dfs(x-1,y,board);
        dfs(x+1,y,board);
        dfs(x,y+1,board);
        dfs(x,y-1,board);
        return ;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][m-1]=='O')
                dfs(i,m-1,board);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(0,i,board);
            if(board[n-1][i]=='O')
                dfs(n-1,i,board);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};