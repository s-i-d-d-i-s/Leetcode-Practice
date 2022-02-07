class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange,int empty=0) {        
        int res = numBottles;
        empty += numBottles;
        if(empty < numExchange) return res;
        return res + numWaterBottles(empty/numExchange,numExchange,empty%numExchange);
    }
};