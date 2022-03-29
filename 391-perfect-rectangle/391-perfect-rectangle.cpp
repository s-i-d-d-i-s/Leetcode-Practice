class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        map<pair<long,long>,int> freq;
        
        long xMax = INT_MIN;
        long xMin = INT_MAX;
        
        long yMax = INT_MIN;
        long yMin = INT_MAX;
        
        
        long totalArea = 0;
        
        for(auto x:rectangles){
            pair<int,int> bl = {x[0],x[1]};
            pair<int,int> tr = {x[2],x[3]};
            pair<int,int> br = {x[2],x[1]};
            pair<int,int> tl = {x[0],x[3]};
            
            freq[bl]++;
            freq[br]++;
            freq[tl]++;
            freq[tr]++;
            
            long area = (long)(x[2]-x[0])*(long)(x[3]-x[1]);
            
            totalArea += area;
            
            xMax = max({(int)xMax,x[0],x[2]});
            xMin = min({(int)xMin,x[0],x[2]});
            yMax = max({(int)yMax,x[1],x[3]});
            yMin = min({(int)yMin,x[1],x[3]});
            
        }
        multiset<pair<int,int>> corners;
        for(auto x:freq){
            if(x.second%2 == 1){                
                corners.insert(x.first);
            }
        }
        
        if(corners.size() != 4) return false;
        
        for(auto x:{xMax,xMin}){
            for(auto y:{yMax,yMin}){
                pair<int,int> currentCorner = {x,y};
                if(corners.find(currentCorner) == corners.end()) return false;
            }
        }
        
        long actualTotalArea = (xMax-xMin)*(yMax-yMin);
        
        
        if(actualTotalArea != totalArea) return false;
        
        return true;
    }
};