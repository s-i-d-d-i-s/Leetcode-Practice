class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,vector<int>> line;
        for(auto x:buildings){
            int left = x[0];
            int right = x[1];
            int height = x[2];  
            
            line[left].push_back(x[2]);            
            line[right].push_back(-x[2]);
        }
        // for(auto x:line){
        //     cout << x.first << " " << x.second << endl;
        // }
        vector<vector<int>> result;
        int last=0;
        multiset<int> cur;
        for(auto x:line){
            for(int y:line[x.first]){
                if(y>0)
                    cur.insert(y);
                else
                    cur.erase(cur.find(-y));
            }            
            int current_height = cur.size()>0?*(--cur.end()):0;            
            
            if(current_height != last){
                result.push_back({x.first,current_height});
                last=current_height;
            }
        }
        return result;
    }
};