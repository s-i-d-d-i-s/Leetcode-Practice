class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        
        int colBegin = 0;
        int colEnd = matrix[0].size()-1;
        
        while(rowBegin <= rowEnd and colBegin <= colEnd){
            // go right 
            for(int i=colBegin;i<=colEnd;i++){
                res.push_back(matrix[rowBegin][i]);
            }
            
            rowBegin++;
            if(rowBegin > rowEnd or colBegin > colEnd) break;
            
            // go down
            for(int i=rowBegin;i<=rowEnd;i++){
                res.push_back(matrix[i][colEnd]);
            }
            
            colEnd--;
            if(rowBegin > rowEnd or colBegin > colEnd) break;
            // go left
            for(int i=colEnd;i>=colBegin;i--){
                res.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            if(rowBegin > rowEnd or colBegin > colEnd) break;
            
            // go up
            for(int i=rowEnd;i>=rowBegin;i--){
                res.push_back(matrix[i][colBegin]);
            }
            
            colBegin++;
        }
        return res;
    }
};