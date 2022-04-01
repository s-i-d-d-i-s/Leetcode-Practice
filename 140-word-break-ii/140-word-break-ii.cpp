class Solution {
public:
    vector<string> result;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string path;
        dfs(0,s,wordDict,path);
        return result;
    }
    
    void dfs(int idx,string &s,vector<string>& wordDict,string &path){
        if(idx>=s.length()){
            path.pop_back();
            result.push_back(path);
            path+=" ";
            return;
        }
        for(auto x:wordDict){
            int ln = x.length();
            string cur = s.substr(idx,ln);
            if(cur == x){
                path += x;
                path += ' ';                
                dfs(idx+ln,s,wordDict,path);                
                for(int i=0;i<ln+1;i++) path.pop_back();                
            }
        }
        return;
    }
};