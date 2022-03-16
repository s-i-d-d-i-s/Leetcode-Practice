class Solution {
public:
    bool doesIntersect(vector<int> &a,vector<int> &b){
        return max(a[0],b[0]) < min(a[1],b[1]);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> stk;
        int result=0;
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        stk.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(doesIntersect(intervals[i],stk.back())){
                result++;
            }else{
                stk.push_back(intervals[i]);
            }
        }
        return result;
    }
};