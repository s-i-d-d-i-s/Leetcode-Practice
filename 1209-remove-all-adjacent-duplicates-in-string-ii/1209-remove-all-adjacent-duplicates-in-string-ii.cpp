class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<pair<char,int>> stk;
        stk.push_back({s[0],1});
        for(int i=1;i<n;i++){
            if(stk.size()>0  and stk.back().first == s[i]){
                stk.push_back({s[i],stk.back().second+1});
                while(stk.size()>0 and stk.back().second==k){
                    for(int i=0;i<k;i++){
                        stk.pop_back();
                    }
                }
            }else{
                stk.push_back({s[i],1});
            }
        }
        string result="";
        for(auto x:stk){
            result += x.first;
        }
        return result;
    }
};