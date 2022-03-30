class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        depthFirstSearch(board,0);
        return;
    }
    
    bool depthFirstSearch(vector<vector<char>>& board,int index){
        if(index>=81) return isValidSudoku(board);
        int row = index/9;
        int col = index%9;
        
        if(!isValidSudoku(board)) return false;
        
        if(board[row][col] != '.') return depthFirstSearch(board,index+1);
        
        for(int i=1;i<=9;i++){
            board[row][col]=i+'0';
            if(depthFirstSearch(board,index+1)) return true;
            board[row][col]='.';
        }
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedrows[9][9] = {0};
        int usedcols[9][9] = {0};
        int usedsqrs[9][9] = {0};
        
        for(int i = 0; i < 9; i++){
            int sqrr = i/3;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - 49;
                    int sqr = sqrr * 3 + (j/3);
                    if(usedrows[i][num] || usedcols[j][num] || usedsqrs[sqr][num]){
                        return false;
                    }
                    usedrows[i][num] = 1;
                    usedcols[j][num] = 1;
                    usedsqrs[sqr][num] = 1;
                }
            }
        }
        return true;
    }
};
