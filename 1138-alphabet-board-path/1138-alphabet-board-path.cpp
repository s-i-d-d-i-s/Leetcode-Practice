class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        map<char,pair<int,int>> getCell;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].length();j++){
                getCell[board[i][j]]={i,j};
            }
        }
        
        pair<int,int> cur={0,0};
        string res="";
        for(int i=0;i<target.length();i++){
            if(target[i]=='z'){
                if(board[cur.first][cur.second]=='z'){
                    res+="!";
                }else{
                    pair<int,int> dest = getCell['u'];
                    moveToCell(res,cur,dest,false);
                    dest = getCell['z'];
                    moveToCell(res,cur,dest);
                }
            }else{
                pair<int,int> dest = getCell[target[i]];
                moveToCell(res,cur,dest);
            }
        }
        return res;
    }
    
    void moveToCell(string &path,pair<int,int> &source,pair<int,int> destination,bool addIt=true){
        while(source.first < destination.first){
            path+="D";
            source.first++;
        }
        while(source.first > destination.first){
            path+="U";
            source.first--;
        }
        while(source.second < destination.second){
            path+="R";
            source.second++;
        }
        while(source.second > destination.second){
            path+="L";
            source.second--;
        }
        if(addIt)
            path+="!";
    }
};