class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++){
            int c_1 = count(mat[i].begin(),mat[i].end(),1);
            v.push_back({c_1,i});
        }
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b){        
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        vector<int> result;
        for(auto x:v){
            if(k-->0)
                result.push_back(x.second);
        }
        return result;
    }
};