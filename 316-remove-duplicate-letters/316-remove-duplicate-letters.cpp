class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        int freq[26]={0};
        
        for(char c:s)
            freq[c-'a']++;
        
        for(char c:s){
            freq[c-'a']--;
            if(result.size()==0){
                result.push_back(c);
            }else{
                if(result.find(c) != string::npos) continue;
                
                while(result.size()>0 and freq[result.back() - 'a']>0 and result.back() > c){
                    result.pop_back();
                }
                result.push_back(c);
            }
        }
        return result;
    }
};