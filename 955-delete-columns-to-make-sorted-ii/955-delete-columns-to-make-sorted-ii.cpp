class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n = a.size();
        int m = a[0].length();
        vector<bool> ignore(n);
        
        int result=0;
        
        for(int i=0;i<m;i++){
            bool removeCol=false;
            for(int j=1;j<n;j++){
                if(ignore[j])continue;
                if(a[j][i]<a[j-1][i]){
                    removeCol=true;
                }
            }
            if(removeCol)
                result++;
            else{
                for(int j=1;j<n;j++){
                    if(ignore[j])continue;
                    if(a[j][i] == a[j-1][i]){
                        
                    }else{
                        ignore[j]=1;
                    }
                }
            }
        }
        return result;
    }
};