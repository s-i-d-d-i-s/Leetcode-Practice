class Solution {
public:
    bool isValid(string &a){
        int balance =0 ;
        for(char x:a){
            if(x=='('){
                balance++;
            }else{
                balance--;
            }
            if(balance<0)return false;
        }
        return balance == 0;
    }
    vector<string> generateParenthesis(int n) {
        int lim = powl(2,2*n);
        vector<string> result;
        for(int i=0;i<lim;i++){
            int num = i;
            string cur;
            for(int j=0;j<2*n;j++){
                if(num&1){
                    cur.push_back('(');
                }else{
                    cur.push_back(')');
                }
                num/=2;
            }
            if(isValid(cur)){
                result.push_back(cur);
            }
        }
        return result;
    }
};