class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string b = s+s;
        return b.substr(1).find(s) < s.length()-1;
    }
};