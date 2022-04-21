class Solution {
public:
    bool checkPerfectNumber(int num) {
        if( num == 1)return false;
        int sum = 1;
        for(int i=2;i*i<=num;i++){
            if(num % i == 0){
                int one = i;
                int two = num/one;
                sum += one;
                if(one != two){
                    sum += two;
                }
            }
        }
        return sum == num;
    }
};