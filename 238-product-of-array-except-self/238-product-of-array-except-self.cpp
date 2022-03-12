class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1, total_non_zero=1;
        int count_of_zero = 0;
        for(int x : nums){
            total *= x;
            if(x == 0) count_of_zero++;
            else total_non_zero*= x;
        }
        vector<int> result;
        for(int x:nums){
            if(total == 0){
                if(x==0 and count_of_zero == 1){
                    result.push_back(total_non_zero);
                }else{
                    result.push_back(0);
                }
            }else{
                double current = powl(x,-1)*total;
                result.push_back(current);
            }
        }
        return result;
    }
};