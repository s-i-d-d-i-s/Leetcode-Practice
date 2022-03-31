class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int result=0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // r1 -> i, r2->i
                auto currentRow = getRow(matrix,i,j);
                result += solve1D(currentRow,target);
            }
        }
        return result;
    }
    int solve1D(vector<int> &nums,int k){
        int n = nums.size();
        map<int,int> idx;
        int pref=0;
        int res=0;
        idx[0]=1;
        for(int i=0;i<n;i++){
            pref += nums[i];
            if(idx.find(pref-k) != idx.end()){
                res+=idx[pref-k];
            }
            idx[pref]++;
        }
        return res;
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