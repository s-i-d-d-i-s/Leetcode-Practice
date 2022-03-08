class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        map<int,int> isPushed;
        int i=0;
        int j=0;
        stack<int> stack;
        while(i<pushed.size() and j<popped.size()){
            if(stack.size()>0 and stack.top() == popped[j] and isPushed[popped[j]] == true){
                stack.pop();
                isPushed[popped[j]]=false;
                j++;
            }else if(isPushed[pushed[i]] == false){
                stack.push(pushed[i]);
                isPushed[pushed[i]]=true;
                i++;
            }else{
                return false;
            }
        }
        while(i<pushed.size()){
            if(isPushed[pushed[i]] == false){
                isPushed[pushed[i]]=true;
                i++;
            }else{
                return false;
            }
        }
        while(j<popped.size()){
            if(stack.size()>0 and stack.top() == popped[j] and isPushed[popped[j]] == true){
                stack.pop();
                isPushed[popped[j]]=false;
                j++;
            }else{
                return false;
            }
        }
        return true;
    }
};