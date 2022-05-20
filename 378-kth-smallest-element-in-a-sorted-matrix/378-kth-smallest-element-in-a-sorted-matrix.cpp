class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<pair<int,pair<int,int>>> ms;
        for(int i=0;i<matrix.size();i++){
            ms.insert({matrix[i][0],{i,0}});
        }
        
        int result=0;
        while(k--){
            auto [sum,cord] = *ms.begin();
            ms.erase(ms.begin());
            auto [r,c] = cord;
            result = sum;
            if(c+1 < matrix[r].size()){
                ms.insert({matrix[r][c+1],{r,c+1}});
            }
        }
        
        return result;
    }
    void display(multiset<pair<int,pair<int,int>>> &ms){
        cout << "Display" << endl;
        for(auto x:ms){
            cout << x.first << " " << x.second.first << " " << x.second.second << endl;
        }
        cout << endl;
    }
};