class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_map<string,bool> has;
        for(auto x:folder){
            has[x] = true;
        }
        vector<string> result;
        for(auto x:folder){
            string temp = x;
            temp = goBack(temp);
            bool parentFound = false;
            while(temp.length()>0 and !parentFound){
                if(has.find(temp)!=has.end()){
                    parentFound=true;
                }else{
                    temp = goBack(temp);
                }
            }
            if(!parentFound){
                result.push_back(x);
            }
        }
        return result;
    }
    string goBack(string &a){
        if(a.length()==0)return "";
        while(a.back()!='/'){
            a.pop_back();
        }
        a.pop_back();
        return a;
    }
};