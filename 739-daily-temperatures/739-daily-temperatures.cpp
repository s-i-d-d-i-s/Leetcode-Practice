class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n = temperatures.size();
        vector<int> result(n);
        for(int i=n-1;i>=0;i--){
            while(stk.size()>0 and stk.top().first<=temperatures[i]){
                stk.pop();
            }
            if(stk.size()==0){
                stk.push({temperatures[i],i});
                result[i]=0;
            }else{
                int distance = stk.top().second-i;
                result[i]=distance;
                stk.push({temperatures[i],i});
            }
        }
        return result;
    }
};