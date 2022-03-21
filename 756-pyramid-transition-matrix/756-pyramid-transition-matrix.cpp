class Solution {
public:
    unordered_map<string, vector<char>> m;
    unordered_set<string> invalid;
    bool pyramidTransition(string bottom, vector<string>& allowed) {        
        for(auto& s : allowed)
            m[s.substr(0, 2)].push_back(s.back());
        
        return canSolve(0,bottom.length()-1,bottom,"");
    }
    bool canSolve(int idx,int n,string bottom,string cur){
        if(bottom.length()==1)return true;
        
        if(invalid.find(bottom) != invalid.end()) return false;
        
        if(idx>=n)
            return canSolve(0,cur.length()-1,cur,"");
        
        
        string pat="";
        pat.push_back(bottom[idx]);
        pat.push_back(bottom[idx+1]);
        for(char c:m[pat])
            if(canSolve(idx+1,n,bottom,cur+c)){
                return true;
            }
            
        
        invalid.insert(bottom);
        return false;
    }
};