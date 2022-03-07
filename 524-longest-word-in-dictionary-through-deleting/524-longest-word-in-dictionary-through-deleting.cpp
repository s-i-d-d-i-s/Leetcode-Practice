class Solution {
public:
    bool isSub(string &a,string &b){
        int i=0;
        int j=0;
        while(i<a.length() and j<b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else i++;
        }
        return j==b.length();
    }
    
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string result="";
        for(auto x:dictionary){
            if(isSub(s,x)){
                if(x.length()>result.length()){
                    result=x;
                }else if(x.length()==result.length()){
                    result=min(result,x);
                }
            }
        }
        return result;
    }
};