class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long sign = 1;
        if((dividend<0 and divisor>0) or (dividend>0 and divisor<0)){
            sign*=-1;
        }
        
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long long result=0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(dividend >= divisor){
            int mul = 0;
            while(dividend>=(divisor<<mul)){
                mul++;
            }
            mul--;
            result+=(1<<mul);
            dividend-=(divisor<<mul);
        }
        return result*sign;
    }
};