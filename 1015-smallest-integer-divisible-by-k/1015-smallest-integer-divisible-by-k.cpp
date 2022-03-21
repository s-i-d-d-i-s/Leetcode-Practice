class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)return 1;
        int result=0;
        int cur=0;
        while(result<=k+5){
            cur *= 10;
            cur++;
            result++;
            cur %= k;
            if(cur==0) return result;            
        }
        return -1;
    }
};