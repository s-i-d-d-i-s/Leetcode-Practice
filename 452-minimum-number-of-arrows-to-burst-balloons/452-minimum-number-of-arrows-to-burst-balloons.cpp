class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int> cur = points[0];
        
        int result = 1;
        for(auto x:points){
            if(doesIntersect(cur,x)){
                cur = mergeIt(cur,x);
            }else{
                result++;
                cur=x;
            }
        }
        return result;
    }
    bool doesIntersect(vector<int> &a,vector<int> &b){
        return max(a[0],b[0]) <= min(a[1],b[1]);
    }
    vector<int> mergeIt(vector<int> &a,vector<int> &b){
        return {max(a[0],b[0]) , min(a[1],b[1])};
    }
};