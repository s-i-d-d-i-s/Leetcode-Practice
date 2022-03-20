class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows(n),cols(m);
        int result=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1){
                    result++;
                    rows[i]++;
                    cols[j]++;
                }
                    
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1 and rows[i]==1 and cols[j]==1)
                    result--;
                   
        return result;
    }
};