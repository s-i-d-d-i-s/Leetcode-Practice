class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> colPrefix = mat;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                colPrefix[i][j] = mat[i][j] + colPrefix[i-1][j];
            }
        }
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> line;
                for(int k=0;k<m;k++){
                    int top = i;
                    int bottom = j;
                    int sum = colPrefix[bottom][k] - (top-1>=0?colPrefix[top-1][k]:0);
                    line.push_back(sum);
                }
                int span = j-i+1;
                int solutionOfLine = solveLine(line,span);
                result += solutionOfLine;
            }
        }
        return result;
    }
    
    int solveLine(vector<int> &line,int span){
        int result=0;
        int count=0;
        for(int x:line){
            if(x == span){
                count++;
            }else{
                if(count>0)
                    result += ((count *(count+1))/2);                
                count=0;
            }
        }
        if(count>0)
            result += ((count *(count+1))/2);
        return result;
    }
};

