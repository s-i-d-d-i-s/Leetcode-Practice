class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> smallLeft(n),smallRight(n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(stk.size()>0 and a[stk.top()]>=a[i]){
                stk.pop();
            }
            smallLeft[i] = (stk.size()>0?stk.top():-1);
            stk.push(i);
        }
        while(stk.size()>0) stk.pop();
        for(int i=n-1;i>=0;i--){
            while(stk.size()>0 and a[stk.top()]>=a[i]){
                stk.pop();
            }
            smallRight[i] = (stk.size()>0?stk.top():n);
            stk.push(i);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            int length  = smallRight[i] - smallLeft[i] - 1;
            res = max(res, length*(a[i]));
        }
        return res;
    }
};