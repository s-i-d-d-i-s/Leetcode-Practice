class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return validPalindrome(s,l,r-1) or validPalindrome(s,l+1,r);
            }
        }
        return true;
    }
    bool validPalindrome(string &s,int l,int r) {
        while(l<r){
            if(s[l] == s[r]) {
                l++;
                r--;
            }else return false;
        }
        return true;
    }
};