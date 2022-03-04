class Solution {
public:
    vector<double> getNextRow(vector<double> &row){
        int n = row.size();
        vector<double> result(n+1,0.0);
        for(int i=0;i<n;i++){
            double excess = 0;
            if(row[i]>1)
                excess = row[i]-1.0;
            result[i]+=excess/2.0;
            result[i+1]+=excess/2.0;
        }
        return result;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currentRow;
        currentRow.push_back(poured);
        while(query_row-->0){
            currentRow = getNextRow(currentRow);
        }
        return min(1.0,currentRow[query_glass]);
    }
};