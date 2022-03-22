class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probab(n,0);
        
        map<int,vector<pair<int,double>>> adjList;
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        set<pair<double,int>> Q;
        Q.insert({1,start});
        probab[start]=1;
        while(Q.size()>0){
            auto ed = Q.end();
            ed--;
            auto [pro,node] = *ed;
            Q.erase(ed);
            for(auto x:adjList[node]){
                int childNode = x.first;
                if(probab[childNode]<pro*x.second){
                    probab[childNode]=pro*x.second;
                    Q.insert({probab[childNode],childNode});                    
                }
            }
        }
        return probab[end];
    }
};