class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> cord[4];
        for(int i=0;i<4;i++) cord[i].resize(n);
        for(int i=0;i<n;i++){
            cord[0][i] = arr1[i]+arr2[i]+i;
            cord[1][i] = arr1[i]+arr2[i]-i;
            cord[2][i] = arr1[i]-arr2[i]+i;
            cord[3][i] = arr1[i]-arr2[i]-i;            
        }
        for(int i=0;i<4;i++) sort(cord[i].begin(),cord[i].end());
        int result=INT_MIN;
        for(int i=0;i<4;i++) result = max(result,cord[i].back()-cord[i][0]);
        return result;
    }
};