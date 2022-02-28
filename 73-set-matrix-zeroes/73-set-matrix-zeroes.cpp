class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool zeroRow = false;
        bool zeroCol = false;
        
        // Check if the 1st col becomes 0
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)zeroCol=true;
        }
        
        // Check if the 1st row becomes 0
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0)zeroRow=true;
        }
        
        // Process all except 1st row/col
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        // Apply all except 1st row/col
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0 or matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<n and zeroCol;i++){
            matrix[i][0]=0;
        }
        for(int i=0;i<m and zeroRow;i++){
            matrix[0][i]=0;
        }
    }
     
};