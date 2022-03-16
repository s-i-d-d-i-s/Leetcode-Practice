class Solution {
public:
    vector<int> result;
    
    void dfs(int cur,int target){
        if(cur>target){
            return;
        }
        result.push_back(cur);
        for(int i=0;i<=9;i++)
            if(cur*10+i<=target)
                dfs(cur*10+i,target);
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            dfs(i,n);
        }
        return result;
    }
    
};