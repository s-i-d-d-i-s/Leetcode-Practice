class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp,mp2;
        int n = s.length();
        if(t.length() != n)return false;
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i])
                    return false;
            }
            if(mp2.find(t[i]) != mp2.end()){
                if(mp2[t[i]] != s[i])
                    return false;
            }
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};