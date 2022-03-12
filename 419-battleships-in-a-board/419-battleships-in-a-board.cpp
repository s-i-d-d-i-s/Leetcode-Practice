class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( (i==0 or board[i-1][j]=='.') and (j==0 or board[i][j-1]=='.'))
                    result+=(board[i][j]=='X');
            }
        }
        return result;
    }
};