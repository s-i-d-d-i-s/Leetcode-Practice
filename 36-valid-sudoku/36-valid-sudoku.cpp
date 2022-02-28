class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<int,int> freq,freq2;
            for(int j=0;j<9;j++){
                freq[board[i][j]]++;
                freq2[board[j][i]]++;
                if(freq[board[i][j]] >1 and board[i][j]!='.')return false;
                if(freq2[board[j][i]] >1 and board[j][i]!='.')return false;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_map<int,int> freq;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        freq[board[i+k][j+l]]++;
                        if(freq[board[i+k][j+l]]>1 and board[i+k][j+l]!='.'){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};