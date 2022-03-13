class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(auto x:words){
            if(doesMatch(x,pattern)){
                result.push_back(x);
            }
        }
        return result;
    }
    bool doesMatch(string a,string b){
        // a -> pattern , b-> target
        auto perm1 = getPerm(a);
        auto perm2 = getPerm(b);
        for(int i=0;i<a.length();i++){
            a[i]=perm1[a[i]];
            b[i]=perm2[b[i]];
        }
        return a==b;
    }
    unordered_map<char,int> getPerm(string &a){
        unordered_map<char,int> result;
        int idx=0;
        for(char x:a){
            if(result.find(x) != result.end()) continue;
            result[x]=idx++;
        }
        return result;
    }
};