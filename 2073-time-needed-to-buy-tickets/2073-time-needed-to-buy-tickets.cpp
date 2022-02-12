class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> dq;
        int n = tickets.size();
        for(int i=0;i<n;i++){
            dq.push({i,tickets[i]});
        }
        int res=0;
        while(dq.size()>0){
            auto cur = dq.front();
            res++;
            dq.pop();
            cur.second--;
            if(cur.first==k and cur.second==0){
                return res;
            }
            if(cur.second==0)continue;
            dq.push(cur);
        }
        return -1;
    }
};