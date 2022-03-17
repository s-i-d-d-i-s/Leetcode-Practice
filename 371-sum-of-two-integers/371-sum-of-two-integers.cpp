class Solution {
public:
    int getSum(unsigned int a,unsigned int b) {
        if(a==0 or b==0){
            return max(a,b);
        }
        unsigned int carry = a&b;
        unsigned int sum = a^b;
        return getSum(sum,carry<<1);
    }
};