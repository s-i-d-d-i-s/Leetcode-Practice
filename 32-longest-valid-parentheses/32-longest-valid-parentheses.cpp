class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length();
        vector<int> stk;
        
        for(int i=0;i<n;i++){
            if(stk.size() == 0){
                stk.push_back(i);
            }else{
                if(s[i] == '('){
                    stk.push_back(i);
                }else{
                    if(s[stk.back()] == '('){
                        stk.pop_back();
                    }else{
                        stk.push_back(i);
                    }                    
                }
            }
        }
        if(stk.size()==0) return n;
        int result=0;
        for(int i=0;i<stk.size();i++){
            int idx = stk[i];

            int left = i-1>=0?stk[i-1]:-1;
            
            int right = i+1<stk.size()?stk[i+1]:n;
            
            result = max(result,idx-left-1);
            result = max(result,right-idx-1);
        }
        return result;
    }
};