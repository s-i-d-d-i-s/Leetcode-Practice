class Solution {
public:
    vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    
    void depthFirstSearch(int idx,string &digits,string &path){
        if(idx>=digits.size()){
            if(path.length()>0)
                result.push_back(path);
            return;
        }
        for(char x:keys[digits[idx]-'0']){
            path.push_back(x);
            depthFirstSearch(idx+1,digits,path);
            path.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        string path="";
        
        depthFirstSearch(0,digits,path);
        return result;
    }
};