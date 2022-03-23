class Solution {
public:
    int brokenCalc(int startValue, int target) {
        return solve(target,startValue);
    }
    int solve(int y,int x){
        if(y==x) return 0;        
        if(x>=y) return x-y;
        if(y&1)return 1+solve(y+1,x);                
        return 1+solve(y/2,x);
    }
};