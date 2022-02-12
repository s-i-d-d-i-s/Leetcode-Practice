class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res=0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                res += min(tickets[k],tickets[i]);
            }else{
                res += min(tickets[k]-1,tickets[i]);
            }
        }
        return res;
    }
};