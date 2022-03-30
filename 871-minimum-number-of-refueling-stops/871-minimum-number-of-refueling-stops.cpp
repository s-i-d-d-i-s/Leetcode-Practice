class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        multiset<int> options;
        
        if(stations.size()>0)
            sort(stations.begin(),stations.end(),[](vector<int> &a,vector<int> &b){
                return a[0]<b[0];
            });
        
        if(stations.size() == 0 or stations.back()[0] < target)
            stations.push_back({target,0});        
        
        if(stations[0][0] != 0)
            stations.push_back({0,0});
        
        sort(stations.begin(),stations.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });
        
        int currentPosition = stations[0][0];
        int result=0;

        for(auto x:stations){
            if(x[0]>target) break;
            
            int fuelBurnt = x[0] - currentPosition;
            
            if(startFuel >= fuelBurnt){
                options.insert(x[1]);
                startFuel -= fuelBurnt;
                currentPosition = x[0];
            }else{
                
                while(options.size()>0 and startFuel < fuelBurnt){
                    auto it = --options.end();
                    int refill = *it;
                    options.erase(it);
                    startFuel+=refill;
                    result++;
                }
                if(startFuel < fuelBurnt) return -1;                    
                options.insert(x[1]);
                startFuel -= fuelBurnt;
                currentPosition = x[0];
            }
        }
        if(currentPosition < target) return -1; 
        return result;
    }
};