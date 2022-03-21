class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0)return -1;
        int result=1;
        int cur=1;
        while(cur % k !=0 and result<=1e5){
            cur *= 10;
            cur++;
            cur %= k;
            result++;
        }
        if(result>=1e5) return -1;
        return result;
    }
};