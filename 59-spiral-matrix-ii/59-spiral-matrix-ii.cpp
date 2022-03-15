class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {        
        int colBegin=0;
        int colEnd=n-1;
        
        int rowBegin=0;
        int rowEnd=n-1;
        
        vector<vector<int>> matrix(n,vector<int>(n,0));
        
        int currentElement = 1;
        
        while(colBegin<=colEnd and rowBegin<=rowEnd){
            for(int i=colBegin;i<=colEnd;i++){
                matrix[rowBegin][i] = currentElement++;
            }
            rowBegin++;
            if(rowBegin>rowEnd)break;
            for(int i=rowBegin;i<=rowEnd;i++){
                matrix[i][colEnd] = currentElement++;
            }
            colEnd--;
            if(colEnd<colBegin)break;
            for(int i=colEnd;i>=colBegin;i--){
                matrix[rowEnd][i] = currentElement++;
            }
            rowEnd--;
            if(rowEnd<rowBegin)break;
            for(int i=rowEnd;i>=rowBegin;i--){
                matrix[i][colBegin] = currentElement++;                
            }
            colBegin++;
        }
        return matrix;
    }
    
    
};