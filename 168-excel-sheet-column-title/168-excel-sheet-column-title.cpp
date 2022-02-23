class Solution {
public:
    string convertToTitle(int columnNumber) {
        //26^3*val(c3) + 26^2*val(c2) + 26*val(c1)
        string res;
        while(columnNumber>0){
            columnNumber--;
            int temp = columnNumber%26;
            res.push_back(temp+'A');
            columnNumber/=26;
        }
        reverse(res.begin(),res.end());
        return res;

    }
};