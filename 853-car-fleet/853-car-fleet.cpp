class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<speed.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        int n = v.size();
        int result = 1;
        pair<int,int> last = v.back();
        double timeForDestination = (target - last.first)/(double)last.second;
        // (0,1) (3,3) (5,1) (8,4) (10,2)
        for(int i=n-2;i>=0;i--){
            if(v[i].second>last.second){
                double gap = last.first - v[i].first;
                double relativeVelocity = v[i].second - last.second;
                double timeToFleet = gap/relativeVelocity;
                if(timeToFleet <= timeForDestination){
                    
                }else{
                    result++;
                    last = v[i];
                    timeForDestination = (target - last.first)/(double)last.second;
                }
            }else{
                result++;
                last = v[i];
                timeForDestination = (target - last.first)/(double)last.second;
            }
        }
        /*
            10
            [6,8]
            [3,2]
        */
        return result;
    }
};