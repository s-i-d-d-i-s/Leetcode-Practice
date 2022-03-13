class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1,p2,p3,p4};
        sort(points.begin(),points.end());
        for(int i=0;i<3;i++)
            if(points[i]==points[i+1])return false;
        
        do{
            if(isValid(points[0],points[1],points[2],points[3])) return true;
        }while(next_permutation(points.begin(),points.end()));
        return false;
    }
    
    bool isValid(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        return getDist(p1,p2)==getDist(p3,p4) and getDist(p1,p4)==getDist(p2,p3)
               and getDist(p1,p2) == getDist(p1,p4) and getDist(p1,p3)==getDist(p2,p4);
    }
    
    int getDist(vector<int>& a, vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
};