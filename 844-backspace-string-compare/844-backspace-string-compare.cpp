class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getWord(s) == getWord(t);
    }
    string getWord(string a){
        string result="";
        for(auto x:a){
            if(x=='#'){
                if(result.length()>0) result.pop_back();
            }else
                result.push_back(x);
        }
        return result;
    }
};