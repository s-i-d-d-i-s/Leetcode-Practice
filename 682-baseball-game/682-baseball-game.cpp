class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        for(auto x:ops){
            if(x == "+"){
                int n = stk.size();
                stk.push_back(stk[n-1]+stk[n-2]);
            }else if(x == "C"){
                stk.pop_back();
            }else if(x == "D"){
                int n = stk.size();
                stk.push_back(stk[n-1]*2);
            }else{
                stk.push_back(stoi(x));
            }
        }
        return accumulate(stk.begin(),stk.end(),0);
    }
};