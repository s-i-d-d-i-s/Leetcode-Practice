class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.length();
        int result=0;
        char last=p[0];
        int len = 1;
        map<char,int> maxSubstr;
        
        maxSubstr[p[0]]=max(maxSubstr[p[0]],len);
        
        for(int i=1;i<p.length();i++){
            if(last == 'z'){
                if(p[i] == 'a'){
                    len++;
                    last = p[i];
                }else{
                    len=1;
                    last = p[i];
                }
            }else{
                if(p[i] == last + 1){
                    len++;
                    last = p[i];
                }else{
                    len=1;
                    last = p[i];
                }
            }
            maxSubstr[p[i]]=max(maxSubstr[p[i]],len);
        }
        
        for(auto x:maxSubstr){
            result += x.second;
        }
        return result;
    }
    int getSubstring(int n){
        return (n*(n+1))/2;
    }
};