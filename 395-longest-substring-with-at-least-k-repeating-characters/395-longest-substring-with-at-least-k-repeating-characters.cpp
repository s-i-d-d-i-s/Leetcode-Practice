class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int> freq;
        for(char x:s){
            freq[x]++;
        }
        int result=0;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]]<k){
                int j=i;
                while(j<s.length() and s[j]==s[i]){
                    j++;
                }
                int left = longestSubstring(s.substr(0,i),k);
                int right = longestSubstring(s.substr(j),k);
                return max(left,right); 
            }
        }
        return s.length();
    }
};