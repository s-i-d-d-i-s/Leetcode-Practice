class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        int freq[26]={0};
        int inResult[26]={0};
        
        for(char c:s)
            freq[c-'a']++;
        
        for(char c:s){
            freq[c-'a']--;
            if(result.size()==0){
                result.push_back(c);
                inResult[c-'a']=1;
            }else{
                if(inResult[c-'a'] == 1) continue;
                
                while(result.size()>0 and freq[result.back() - 'a']>0 and result.back() > c){
                    inResult[result.back()-'a']=0;
                    result.pop_back();
                }
                
                result.push_back(c);
                inResult[c-'a']=1;
            }
        }
        return result;
    }
};