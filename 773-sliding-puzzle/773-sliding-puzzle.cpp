class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        map<vector<vector<int>>,int> visited;
        queue<pair<int,vector<vector<int>>>> Q;
        
        vector<vector<int>> target = {{1,2,3},{4,5,0}};
        
        Q.push({0,board});
        visited[board]=true;
        
        while(Q.size()){
            auto [steps,currentState] = Q.front();
            Q.pop();
            if(currentState == target) return steps;
            int zr,zc;
            getZero(currentState,zr,zc);

            for(int dx:{-1,0,1}){
                for(int dy:{-1,0,1}){
                    if((dx==0 or dy==0)  and (dx!=dy)){
                        int sr = zr+dx; 
                        int sc = zc+dy;
                        if(sr>=0 and sr<2 and sc>=0 and sc<3){
                            auto newBoard = currentState;
                            swap(newBoard[zr][zc],newBoard[sr][sc]);
                            if(!visited[newBoard]){
                                Q.push({steps+1,newBoard});
                                visited[newBoard]=true;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
    
    void showBoard(vector<vector<int>> &board){
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void getZero(vector<vector<int>> &board,int &r,int &c){     

        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    r=i;
                    c=j;
                    return;
                }
            }
        }
    }
};