class Solution {
public:
    int scoreOfParentheses(string s) {
        int result=0;
        int bal=0;
        int n = s.length();
        if(n==0)return 0;
        if(s=="()") return 1;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                bal++;
            }else{
                bal--;
            }
            if(bal==0 and i!=n-1){
                string left = s.substr(0,i+1);
                string right = s.substr(i+1);
                return scoreOfParentheses(left) + scoreOfParentheses(right);
            }
        }
        string trimmedString = s.substr(1,n-2);
        return 2*scoreOfParentheses(trimmedString);
    }
};