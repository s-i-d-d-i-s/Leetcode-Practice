class Solution {
public:
    double myPowUtil(double x, long n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        
        if(n<0){
            return 1/myPowUtil(x,abs(n));
        }
        if(n&1){
            double result = myPowUtil(x,(n-1)/2);
            return x*result*result;
        }

        double result = myPowUtil(x,n/2);
        return result*result;
    }
    double myPow(double x, int n) {
        return myPowUtil(x,n);
    }
};

// 2^(2m) == 2^m * 2^m
// 2^(2m+1) == 2*(2^m * 2^m)