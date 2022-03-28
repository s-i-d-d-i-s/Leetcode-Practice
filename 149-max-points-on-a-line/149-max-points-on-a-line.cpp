class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result=1;
        for(int i=0;i<n;i++){
            map<double,int> freq;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                freq[getSlope(points[i],points[j])]++;
            }
            for(auto x:freq){
                result = max(result,1+x.second);
            }
        }
        return result;
    }
    double getSlope(vector<int> &a,vector<int> &b){
        double yDiff = a[1]-b[1];
        double xDiff = a[0]-b[0];
        if(xDiff == 0) return INT_MAX;
        return yDiff / xDiff;
    }
};