class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> lastFilled;
        unordered_map<int,int> lastEncountered;
        int n = rains.size();
        vector<int> result(n,-1);        
        set<int> q;
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                if(lastFilled.find(rains[i]) != lastFilled.end()){
                    int lastFilledDate = lastFilled[rains[i]];
                    if(q.size()==0) return {};
                    auto it = q.upper_bound(lastFilledDate);
                    if(it == q.end()) return {};
                    int emptyDate = *it;
                    q.erase(it);
                    result[emptyDate] = rains[i];
                }
                lastFilled[rains[i]]=i;
            }else{
                q.insert(i);
            }
        }
        for(int i=0;i<n;i++){
            if(rains[i] == 0 and result[i]==-1){
                result[i]=1;
            }
        }
        return result;
    }
};