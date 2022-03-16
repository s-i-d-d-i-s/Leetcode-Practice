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
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    int up = i-1>=0?result[i-1][j]:INT_MAX;
                    int left = j-1>=0?result[i][j-1]:INT_MAX;
                    if(min(up,left)==INT_MAX)continue;
                    result[i][j] = min(up,left)+1;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j] == 1){
                    int down = i+1<n?result[i+1][j]:INT_MAX;
                    int right = j+1<m?result[i][j+1]:INT_MAX;
                    if(min(down,right)==INT_MAX)continue;
                    result[i][j] = min(result[i][j], min(down,right)+1);
                }
            }
        }
        
       
        return result;
    }
};