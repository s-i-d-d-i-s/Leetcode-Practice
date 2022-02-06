class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int res=0;
        map<char,int> freq;
        while(l<s.length()){
            while(r<s.length()){
                if(freq[s[r]]==1){
                    break;
                }
                freq[s[r]]++;
                r++;
            }
            res = max(res,r-l);
            if(r == s.length()) break;
            while(l<=r and freq[s[r]]==1){
                freq[s[l]]--;
                l++;
            }
        }
        return res;
    }
};