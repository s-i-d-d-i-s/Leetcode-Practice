class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk;
        unordered_map<int,bool> toRemove;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push_back(i);
            }else if(s[i]==')'){ 
                if(stk.size()>0 and s[stk.back()]=='(')
                    stk.pop_back();
                else{
                    stk.push_back(i);
                }
            }
        }
        for(int x:stk){
            toRemove[x]=1;
        }
        string res="";
        for(int i=0;i<s.length();i++){
            if(!toRemove[i]){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};