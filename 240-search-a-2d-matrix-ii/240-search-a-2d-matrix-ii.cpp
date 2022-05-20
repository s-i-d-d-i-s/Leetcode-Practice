class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return search(matrix,target,n,m,0,m-1);
    }
    
    bool search(vector<vector<int>>& matrix, int target,int n,int m,int r,int c) {
        if(r<0 or r>=n or c<0 or c>=m) return false;
        
        if(target > matrix[r][c]){
            return search(matrix,target,n,m,r+1,c);
        }else if(target < matrix[r][c]){
            return search(matrix,target,n,m,r,c-1);
        }else{
            return true;
        }
    }
};