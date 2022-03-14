class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(board[0][0] != -1)return -1;
        int n = board.size();
        vector<int> visited(n*n+1,false),distance(n*n+1,INT_MAX);
        visited[1]=1;
        distance[1]=0;
        queue<int> Q;
        Q.push(1);
        while(Q.size()>0){
            int node = Q.front();
            Q.pop();
            for(int j=1;j<=6;j++){
                int next = node+j;
                if(next>n*n)continue;
                if(!visited[next]){
                    visited[next]=1;                    
                    int value = getBoardValue(next,board);
                    if(value > 0 ){
                        Q.push(value);
                        distance[value] = min(distance[value],1+distance[node]);
                    }else{
                        Q.push(next);
                        distance[next] = min(distance[next],1+distance[node]);
                    }
                }
            }
        }
        if(distance[n*n] == INT_MAX) return -1;
        return distance[n*n];
    }
    int getBoardValue(int num,vector<vector<int>>& board){
        num--;
        int n = board.size();
        int row = num/n;
        int col = num - row*n;
        if(row&1) col = n-col-1;
        row = n-row-1;
        return board[row][col];
    }
};