class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pt=0;
        int pt2=0;
        while(pt<pushed.size() and pt2<popped.size()){
            if(stk.size()>0 and popped[pt2] == stk.top()){
                pt2++;
                stk.pop();
            }else{
                stk.push(pushed[pt]);
                pt++;
            }
        }
        while(stk.size()>0 and popped[pt2] == stk.top()){
            pt2++;
            stk.pop();
        }
        
        return pt>=pushed.size() and pt2>=pushed.size();
    }
};