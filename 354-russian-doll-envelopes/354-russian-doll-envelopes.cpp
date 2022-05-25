class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b){
           if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        
        vector<int> v;
        for(auto x:envelopes){            
            if(v.size()==0){
                v.push_back(x[1]);
            }else{
                auto it = lower_bound(v.begin(),v.end(),x[1]);
                if(it == v.end()){
                    v.push_back(x[1]);
                }else{
                    *it = x[1];
                }
            }
        }
        return v.size();
    }
    
};