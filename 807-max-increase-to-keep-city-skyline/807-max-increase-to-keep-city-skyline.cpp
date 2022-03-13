class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows(n),cols(m);
        for(int i=0;i<n;i++){
            rows[i] = *max_element(grid[i].begin(),grid[i].end());
        }
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++) maxi = max(maxi,grid[j][i]);
            cols[i] = maxi;
        }
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result += (min(rows[i],cols[j])-grid[i][j]);
            }
        }
        return result;
    }
};