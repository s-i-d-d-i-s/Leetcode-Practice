class Solution {
public:
    int countSubstrings(string s) {
        return countOdd(s)+countEven(s);
    }
    int countOdd(string &s){
        int result=0;
        for(int i=0;i<s.length();i++){
            int l=i;
            int r=i;
            while(l>=0 and r<s.length() and s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            int length = r-l+1;            
            result += (length/2 + 1);
        }
        return result;
    }
    int countEven(string &s){
        int result=0;
        for(int i=0;i<s.length()-1;i++){
            int l=i;
            int r=i+1;
            if(s[l]!=s[r])continue;
            while(l>=0 and r<s.length() and s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            int length = r-l+1;            
            result += (length/2);
        }
        return result;
    }
};