class Solution {
public:
    long long sum(long long n){
        return (n*(n+1))/2;
    }
    bool solve(long long n,long long k){
        long long numer = (n-sum(k-1));
        if(numer % k !=0) return false;
        numer /= k;
        return numer >= 1 and numer <= n;
    }
    int consecutiveNumbersSum(int n) {
        int res=0;
        int lim = ceil(sqrt(n));
        for(int i=1;i<=2*lim;i++){
            int f= (solve(n,i));
            res += f;
        }
        return res;
    }
};