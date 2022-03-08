class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        int second_minimum = INT_MAX;
        for(int x:nums){
            if(x<=minimum){
                minimum = x;
            }else if(x>minimum and x<=second_minimum){
                second_minimum=x;
            }else{
                return true;
            }
        }
        return false;
    }
};