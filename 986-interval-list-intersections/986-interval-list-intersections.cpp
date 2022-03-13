class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int pt1=0,pt2=0;
        
        while(pt1<firstList.size() and pt2<secondList.size()){
            int starting = max(firstList[pt1][0],secondList[pt2][0]);
            int ending = min(firstList[pt1][1],secondList[pt2][1]);
            if(starting <= ending)
            result.push_back({starting,ending});
            if(firstList[pt1][1]<secondList[pt2][1])
                pt1++;
            else
                pt2++;
        }
        return result;
    }
};