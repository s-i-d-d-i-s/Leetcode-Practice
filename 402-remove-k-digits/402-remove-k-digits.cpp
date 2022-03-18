class Solution {
public:
    string removeKdigits(string num, int k) {
        string result="";
        for(int i=0;i<num.length();i++){
            if(result.length()==0){
                result.push_back(num[i]);
            }else{
                while(result.length()>0 and result.back()>num[i] and k-->0){
                    result.pop_back();
                }
                result.push_back(num[i]);
            }
        }
        while(result.size()>0 and k-->0)result.pop_back();
        reverse(result.begin(),result.end());
        while(result.size()>0 and result.back()=='0')result.pop_back();
        reverse(result.begin(),result.end());
        if(result.length()==0)result="0";
        
        return result;
    }
};