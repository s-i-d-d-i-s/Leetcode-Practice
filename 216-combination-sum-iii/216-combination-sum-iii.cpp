class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        generate(0,0,n,path,k);
        return result;
    }
    void generate(int mask,int current_sum,int n,vector<int> &path,int k){
        if(path.size()==k){
            if(current_sum == n){
                result.push_back(path);
            }
            return;
        }
        for(int i=1;i<=9;i++){
            bool numberIsVisited = mask&(1<<(i-1));
            if(!numberIsVisited and (path.size()==0 or path.back()<i)){
                path.push_back(i);
                generate(mask|(1<<(i-1)),current_sum + i, n, path,k);
                path.pop_back();
            }
        }
        return;
    }
};