class Solution {
public:
    vector<int> getCleanVersion(string &a){
        string current;
        vector<int> res;
        for(char x:a){
            if(x=='.'){
                res.push_back(stoi(current));
                current="";
            }else{
                current.push_back(x);
            }
        }
        if(current.size()>0){
            res.push_back(stoi(current));
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        auto one = getCleanVersion(version1);
        auto two = getCleanVersion(version2);
        while(one.size()<two.size()){
            one.push_back(0);
        }
        while(one.size()>two.size()){
            two.push_back(0);
        }
        if(one < two){
            return -1;
        }else if(one > two){
            return 1;
        }
        return 0;
    }
};