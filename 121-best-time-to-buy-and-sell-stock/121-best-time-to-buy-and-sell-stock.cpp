class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum_so_far=prices[0];
        int result=0;
        for(int i=1;i<prices.size();i++){
            result = max(result,prices[i]-minimum_so_far);
            minimum_so_far = min(minimum_so_far,prices[i]);
        }        
        return result;
    }
};