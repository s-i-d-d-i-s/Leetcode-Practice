class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        auto elements = getElements(grid);
        k%= elements.size();
        elements = shiftElements(elements,k);
        updateGrid(grid,elements);
        return grid;
    }
    void updateGrid(vector<vector<int>>& grid,vector<int> &elements){
        int pt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j] = elements[pt++];
            }
        }
        return;
    }
    vector<int> getElements(vector<vector<int>>& grid){
        vector<int> result;
        for(auto x:grid){
            for(auto y:x){
                result.push_back(y);
            }
        }
        return result;
    }
    vector<int> shiftElements(vector<int> &a,int k){
        vector<int> result;
        int n = a.size();
        for(int i=0;i<a.size();i++){
            result.push_back(a[(i-k+n)%n]);
        }
        return result;
    }
};