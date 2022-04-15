class Solution {
public:
    int arrangeCoins(int n) {
        long long result=0;
        long long cur=0;
        for(int i=1;;i++){
            if(i+cur <= n){
                result++;
                cur+=i;
            }else break;
        }
        return result;
    }
};