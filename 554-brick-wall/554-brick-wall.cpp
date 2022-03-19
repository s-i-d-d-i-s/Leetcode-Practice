class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> freq;
        for(int i=0;i<wall.size();i++){
            makePrefix(wall[i]);
            wall[i].pop_back();
            for(int x:wall[i]){
                freq[x]++;
            }
        }
        int result=wall.size();
        for(auto x:freq){
            int count = x.second;
            int current = (int)wall.size()-count;
            // cout << x.first << " " << current << endl;
            result = min(result,current);
        }
        return result;
    }
    void makePrefix(vector<int>& wall){
        for(int i=1;i<(int)wall.size();i++){
            wall[i]=wall[i-1]+wall[i];
        }
        return;
    }
};