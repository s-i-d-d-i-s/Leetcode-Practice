class Solution {
public:    
    bool solve(string &a){
        string b=a;
        reverse(b.begin(),b.end());
        return a==b;
    }
    bool isPalindrome(string s) {
        string res;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))
                res.push_back(tolower(s[i]));
            else if(s[i]>='0' and s[i]<='9')
                res.push_back(tolower(s[i]));
        }
        return solve(res);
    }
};