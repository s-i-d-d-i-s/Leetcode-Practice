class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countZero=count(s.begin(),s.end(),'0');
        int countOne=0;
        int result=min(countZero,(int)s.length()-countZero);
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')countOne++;
            else countZero--;
            result=min(countOne+countZero,result);
        }
        return result;
    }
};