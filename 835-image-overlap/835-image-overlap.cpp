class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        set<pair<int,int>> points1,points2;
        for(int i=0;i<img1.size();i++)
            for(int j=0;j<img1[0].size();j++)
                if(img1[i][j] == 1)
                    points1.insert({i,j});
            
        for(int i=0;i<img2.size();i++)
            for(int j=0;j<img2[0].size();j++)
                if(img2[i][j] == 1)
                    points2.insert({i,j});
            
        map<pair<int,int>,int> freq;
        int result=0;
        for(auto x:points1){
            for(auto y:points2){
                freq[{x.first-y.first,x.second-y.second}]++;
                result = max(result,freq[{x.first-y.first,x.second-y.second}]);
            }
        }
        return result;
    }
};