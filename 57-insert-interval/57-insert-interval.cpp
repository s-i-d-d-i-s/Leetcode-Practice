class Solution {
public:
    bool isIntersect(vector<int> &a,vector<int> &b){
        return max(a[0],b[0]) <= min(a[1],b[1]);
    }

    vector<int> merge(vector<int> &a,vector<int> &b){
        vector<int> result = {min(a[0],b[0]),max(a[1],b[1])};
        return result;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }
        bool isInserted=false;
        for(int i=0;i<intervals.size();i++){
            if(!isInserted and intervals[i][0]>newInterval[1]){
                result.push_back(newInterval);
                isInserted=true;
            }
            
            if(!isInserted and isIntersect(intervals[i],newInterval)){
                newInterval = merge(intervals[i],newInterval);
            }else{
                result.push_back(intervals[i]);
            }
            
        }
        if(!isInserted){
            result.push_back(newInterval);
        }
        return result;
    }
};