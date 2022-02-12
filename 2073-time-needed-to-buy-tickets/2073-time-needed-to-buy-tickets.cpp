class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        vector<pair<int,int>> v;
        int n = tickets.size();
        for(int i=0;i<n;i++){
            v.push_back({tickets[i],i});
        }
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        int buf=0;
        for(int i=k+1;i<n;i++){
            if(tickets[i]>=tickets[k]){
                buf++;
            }
        }
        // for(auto x:v){
        //     cout << "(" << x.first << "," << x.second << "), ";
        // }
        // cout << endl;
        int gone = 0;
        int res=0;
        for(int i=0;i<n;i++){
            int left = n-i;
            int cur = v[i].first-gone;
            if(cur>0){
                gone += cur;
                res += left*cur;
            }
            if(v[i].second == k){
                break;
            }
        }
        return res-buf;
    }
};