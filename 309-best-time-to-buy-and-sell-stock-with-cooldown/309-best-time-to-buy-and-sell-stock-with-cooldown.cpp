class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int have_0_get_1 = -prices[0];
        int have_0_get_0 = 0;
        int have_1_put_1 = INT_MIN;
        int have_1_put_0 = INT_MIN;
        for(int i = 1; i< prices.size(); i++){
            int have_0_get_1_next = -prices[i]+have_0_get_0;
            int have_0_get_0_next = max(have_1_put_1,have_0_get_0);
            int have_1_put_1_next = +prices[i] + max(have_1_put_0,have_0_get_1);
            int have_1_put_0_next = max(have_1_put_0,have_0_get_1);
            
            have_0_get_1 = have_0_get_1_next;
            have_0_get_0 = have_0_get_0_next;
            have_1_put_1 = have_1_put_1_next;
            have_1_put_0 = have_1_put_0_next;
            //cout << have_0_get_0 << " " << have_0_get_1 << " " <<  have_1_put_1 << " " << have_1_put_0 << endl;
        }
        return max({have_0_get_1,have_0_get_0,have_1_put_1,have_1_put_0});
    }
};