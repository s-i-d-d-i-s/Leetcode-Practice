class Solution {
public:
    const int MOD = 1e9+7;
    int countOrders(int n) {
        long long res=1;
        for(int i=1;i<=2*n-1;i+=2){
            res *= i;
            res %= MOD;
        }
        res *= fact(n);
        res %= MOD;
        return res;
    }
    long long fact(long long n){
        if(n==0)return 1;
        return (n*fact(n-1))%MOD;
    }
};