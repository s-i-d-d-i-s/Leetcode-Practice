class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp[256],mp2[256];
        memset(mp,-1,sizeof mp);
        memset(mp2,-1,sizeof mp2);
        int n = s.length();
        if(t.length() != n)return false;
        for(int i=0;i<n;i++){
            if(mp[s[i]] != -1){
                if(mp[s[i]] != (t[i]))
                    return false;
            }
            if(mp2[t[i]] != -1){
                if(mp2[t[i]] != (s[i]))
                    return false;
            }
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};