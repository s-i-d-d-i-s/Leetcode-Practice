class Solution {
public:
    vector<string> result;
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
    void generate(int open,int close,string &current){
        if(open==0 and close==0){
            if(isValid(current)){
                result.push_back(current);
            }
            return;
        }
        if(open==0){
            current.push_back(')');
            generate(open,close-1,current);
            current.pop_back();
            return;
        }
        if(close==0){
            current.push_back('(');
            generate(open-1,close,current);
            current.pop_back();
            return;
        }
        current.push_back(')');
        generate(open,close-1,current);
        current.pop_back();
        
        current.push_back('(');
        generate(open-1,close,current);
        current.pop_back();
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string current;
        generate(n,n,current);
        return result;
    }
};