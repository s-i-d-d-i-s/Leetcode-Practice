class Solution {
public:
    int val(char a){
        return a-'A'+1;
    }
    int titleToNumber(string columnTitle) {
        long long res=0;
        int n= columnTitle.length();
        long long idx = 1;
        for(int i=n-1;i>=0;i--){
            res += (idx*val(columnTitle[i]));
            idx*=26;
        }
        return res;
    }
};