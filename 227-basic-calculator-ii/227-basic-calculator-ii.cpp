class Solution {
public:
    int calculate(string s) {
        int num=0;
        char sign = '+';
        stack<int> stk;
        for(char x : s){
            if(x == ' ')continue;
            if(x>='0' and x<='9'){
                num *= 10;
                num += (x-'0');
            }else{
                if(sign == '+'){
                    stk.push(num);
                }else if(sign == '-'){
                    stk.push(-num);
                }else if(sign =='*'){
                    int last = stk.top();
                    stk.pop();
                    stk.push(num*last);
                }else if(sign =='/'){
                    int last = stk.top();
                    stk.pop();
                    stk.push(last/num);
                }
                num=0;
                sign = x;
            }
        }
        if(num>0){
            if(sign == '+'){
                stk.push(num);
            }else if(sign == '-'){
                stk.push(-num);
            }else if(sign =='*'){
                int last = stk.top();
                stk.pop();
                stk.push(num*last);
            }else if(sign =='/'){
                int last = stk.top();
                stk.pop();
                stk.push(last/num);
            }
        }
        int result = 0;
        while(stk.size()>0){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};