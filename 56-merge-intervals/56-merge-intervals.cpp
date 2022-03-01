class Solution {
public:
    bool doesIntersect(vector<int> &a,vector<int> &b){
        return max(a[0],b[0]) <= min(a[1],b[1]);
    }
    
    vector<int> merge(vector<int> &a,vector<int> &b){
        return {min(a[0],b[0]) ,max(a[1],b[1]) };
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<vector<int>> result;
        int n= intervals.size();
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(doesIntersect(result.back(),intervals[i])){
                auto newInterval = merge(result.back(),intervals[i]);
                result.pop_back();
                result.push_back(newInterval);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};