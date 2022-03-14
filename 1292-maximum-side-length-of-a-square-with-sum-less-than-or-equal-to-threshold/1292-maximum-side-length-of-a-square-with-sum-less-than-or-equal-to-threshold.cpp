class GridQuery{
    vector<vector<int>> matrix;
    public:
    GridQuery(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        matrix.resize(n+1);
        for(int i=0;i<=n;i++)matrix[i].resize(m+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i+1][j+1]=matrix[i][j+1]+matrix[i+1][j]-matrix[i][j]+grid[i][j];
            }
        }
    }
    // top-left (r1,c1) bottom right(r2,c2)
    // 0 based;
    int query(int r1,int c1,int r2,int c2){
        return matrix[r2+1][c2+1] - matrix[r1][c2+1] - matrix[r2+1][c1] + matrix[r1][c1];
    }
};

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        
        GridQuery grid(mat);
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int current_best = result;
                int end_row = i+current_best;
                int end_col = j+current_best;
                while(end_row<n and end_col<m and grid.query(i,j,end_row,end_col)<=threshold){
                    result++;
                    end_row++;
                    end_col++;
                }
            }
        }
        return result;
    }
};