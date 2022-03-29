class Solution {
public:
    map<int,int> getPair;
    int calculate(string s) {        
        vector<int> stk;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                stk.push_back(i);
            }else if(s[i]==')'){
                int last=stk.back();
                stk.pop_back();
                getPair[last]=i;
                getPair[i] = last;
            }
        }
        return solve(0,s.length()-1,s);
    }
    
    int solve(int l,int r, string &a){
        if(l>r)
            return 0;
        
        int result=0;
        int num=0;
        int sign=1;
        for(int i=l;i<=r;i++){
            if(isdigit(a[i])){
                num = num*10+(a[i]-'0');
            }else{
                if(a[i] == '('){
                    num += solve(i+1,getPair[i]-1,a);
                    i=getPair[i];
                }else if(a[i]==')'){
                    
                }else if(a[i]=='+'){
                    result += num*sign;
                    num = 0;
                    sign = 1;
                }else if(a[i] == '-'){
                    result += num*sign;
                    num = 0;
                    sign = -1;
                }
            }
        }
        return result+num*sign;
    }
};