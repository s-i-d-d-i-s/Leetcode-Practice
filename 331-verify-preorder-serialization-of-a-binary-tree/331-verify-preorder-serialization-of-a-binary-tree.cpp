class Solution {
public:
    vector<string> split(string &a){
        string current;
        vector<string> result;
        for(int i=0;i<a.size();i++){
            if(a[i]==','){
                result.push_back(current);
                current="";
                continue;
            }
            current.push_back(a[i]);
        }
        if(current.size()>0)result.push_back(current);
        return result;
    }
    bool isValidSerialization(string preorder) {
        auto nodes = split(preorder);
        int allowedNodes=1;
        for(auto node:nodes){
            allowedNodes--;            
            if(allowedNodes < 0) return false;
            if(node != "#") allowedNodes += 2;            
        }
        return allowedNodes == 0;
    }
};