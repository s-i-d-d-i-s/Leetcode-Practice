struct cmp{
    bool operator()(const vector<int> &a,const vector<int> &b) const{
        int dist1 = a[0]*a[0] + a[1]*a[1];
        int dist2 = b[0]*b[0] + b[1]*b[1];
        if(dist1==dist2){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        }
        return dist1<dist2;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<vector<int>,cmp> ss;
        for(auto x:points){
            ss.insert(x);
            if(ss.size()>k){
                auto it = ss.end();
                it--;
                ss.erase(it);
            }
        }
        vector<vector<int>> result(ss.begin(),ss.end());
        return result;
    }
};