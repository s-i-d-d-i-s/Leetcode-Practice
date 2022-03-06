class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<vector<int>,int > doesExist;
        for(auto x:points){
            doesExist[x]=true;
        }
        int result = INT_MAX;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i!=j and points[i][0]<points[j][0] and points[i][1] < points[j][1]){
                    vector<int> topLeft = {points[j][0],points[i][1]};
                    vector<int> bottomRight = {points[i][0],points[j][1]};
                    if(doesExist.find(topLeft)!= doesExist.end() 
                       and doesExist.find(bottomRight)!=doesExist.end()){
                        int width = points[j][1] - points[i][1];
                        int height = points[j][0] - points[i][0];
                        int area= width*height;
                        result = min(result,area);
                    }
                }
            }
        }
        if(result == INT_MAX) result=0;
        return result;
    }
};