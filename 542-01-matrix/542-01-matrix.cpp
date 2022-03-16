class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> Q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    Q.push({i,j});
                }
            }
        }
        
        while(Q.size()>0){
            auto cell = Q.front();
            Q.pop();
            if(cell.first-1>=0 and result[cell.first-1][cell.second] == INT_MAX){
                result[cell.first-1][cell.second]=1+result[cell.first][cell.second];
                Q.push({cell.first-1,cell.second});
            }
            if(cell.first+1<n and result[cell.first+1][cell.second] == INT_MAX){
                result[cell.first+1][cell.second]=1+result[cell.first][cell.second];
                Q.push({cell.first+1,cell.second});
            }
            if(cell.second-1>=0 and result[cell.first][cell.second-1] == INT_MAX){
                result[cell.first][cell.second-1]=1+result[cell.first][cell.second];
                Q.push({cell.first,cell.second-1});
            }
            if(cell.second+1<m and result[cell.first][cell.second+1] == INT_MAX){
                result[cell.first][cell.second+1]=1+result[cell.first][cell.second];
                Q.push({cell.first,cell.second+1});
            }
        }
        return result;
    }
};