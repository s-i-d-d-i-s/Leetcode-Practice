class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 ==0 or k%5==0) return -1;
        int result=1;
        int cur=1;
        while(cur % k !=0){
            cur *= 10;
            cur++;
            cur %= k;
            result++;
        }
        return result;
    }
};