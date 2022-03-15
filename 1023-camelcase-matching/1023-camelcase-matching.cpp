class Solution {
public:
    bool isLow(char a){
        return a>='a' and a<='z';
    }
    bool isSubseq(string &query,string &pattern){
        int pt=0,pt2=0;
        while(pt<query.length() and pt2<pattern.length()){
            if(query[pt]==pattern[pt2]){
                pt++;
                pt2++;
            }else{
                if(isLow(query[pt])){
                    pt++;
                }else{
                    return false;
                }
            }
        }
        while(pt<query.length()){
            if(isLow(query[pt])){
                pt++;
            }else{
                return false;
            }
        }
        return pt2==pattern.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for(auto x:queries){
            result.push_back(isSubseq(x,pattern));
        }
        return result;
    }
};