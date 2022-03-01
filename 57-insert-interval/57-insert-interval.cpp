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
        
        // First add all intervals to the left of the newInterval
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            }else{
                break;
            }
        }
        
        // Add all the intersecting intervals
        for(int i=0;i<intervals.size();i++){
            if(isIntersect(intervals[i],newInterval)){
                newInterval = merge(intervals[i],newInterval);
            }
        }
        result.push_back(newInterval);
        
        
        // Add all the intervals to the right of the updated newInterval
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0] > newInterval[1]){
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};