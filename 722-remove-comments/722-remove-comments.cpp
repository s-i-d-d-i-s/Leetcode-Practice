class Solution {
public:

    vector<string> removeComments(vector<string>& source) {    
        
        bool commentOpen=false;
        vector<string> result;
        string cursor="";
        for(int i=0;i<source.size();i++){
            int m = source[i].length();
            for(int j=0;j<m;j++){
                if(j+1<m and !commentOpen and source[i][j]=='/' and source[i][j+1]=='/'){
                    break;
                }else if(!commentOpen and j+1<m and source[i][j]=='/' and source[i][j+1]=='*'){                    
                    commentOpen=true;                    
                    j++;
                }else if(commentOpen and j+1<m and source[i][j]=='*' and source[i][j+1]=='/'){
                    commentOpen=false;                    
                    j++;
                }else if(!commentOpen){
                    cursor.push_back(source[i][j]);
                }
            }
            if(!commentOpen and cursor.length()>0){
                result.push_back(cursor);
                cursor.clear();
            }
        }
        return result;
    }
};