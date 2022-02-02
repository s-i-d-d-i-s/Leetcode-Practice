

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.length();
        int m = p.length();
        if(m > n)return res;
        
        vector<int> freq_p(26),freq_s(26);
        for(char x:p){
            freq_p[x-'a']++;
        }
        
        for(int i=0;i<m;i++){
            freq_s[s[i]-'a']++;
        }
        if(freq_s == freq_p){
            res.push_back(0);
        }
        
        for(int i=m;i<n;i++){            
            freq_s[s[i-m]-'a']--;
            freq_s[s[i]-'a']++;            
            if(freq_s == freq_p){
                res.push_back(i-m+1);
            }
        }
        return res;
    }
};