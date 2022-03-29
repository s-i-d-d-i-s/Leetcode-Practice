class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int result=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // r1 -> i, r2->i
                auto currentRow = getRow(matrix,i,j);
                result = max(result,solve1D(currentRow,k));
            }
        }
        
        return result;
    }
    
    int solve1D(vector<int> &a,int k){
        int n = a.size();
        
        map<int,int> prefix;
        prefix[0]=0;
        
        int result=INT_MIN;
        
        int cur =0 ;
        
        // pref[r] - k <= pref[l-1]
        
        for(int i=0;i<n;i++){
            cur += a[i];                        
            int need = cur - k;            
            
            auto it = prefix.lower_bound(need);            
            if(it != prefix.end()){
                auto [key,val] = *it;
                if(key>= need){
                    result = max(result,cur-key);
                }
            }
            
            prefix[cur]=i+1;
        }
        return result;
    }
    
    vector<int> getRow(vector<vector<int>>& matrix,int topR,int bottomR){
        int m = matrix[0].size();
        vector<int> result(m);
        for(int i=0;i<m;i++){
            int current=0;
            for(int j=topR;j<=bottomR;j++){
                current += matrix[j][i];
            }
            result[i]=current;
        }
        return result;
    }
};