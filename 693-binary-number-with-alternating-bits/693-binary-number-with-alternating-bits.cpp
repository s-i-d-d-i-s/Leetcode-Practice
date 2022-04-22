class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = !(n&1);
        while(n>0){
            int cur = n&1;
            n/=2;
            if(cur == last) return false;
            last = cur;
        }
        return true;
    }
};