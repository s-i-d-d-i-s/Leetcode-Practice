class Solution {
public:
    map<string,set<string>> adjList;
    
    bool match(string &a,string &b){
        int result=0;
        for(int i=0;i<a.length();i++){
            if(a[i] != b[i]) result++;
        }
        return result==1;
    }
        
    int minMutation(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        for(auto x:bank){
            for(auto y:bank){
                if(match(x,y)){
                    adjList[x].insert(y);
                    adjList[y].insert(x);
                }
            }
        }
        map<string,int> inQ,dist;
        queue<string> Q;
        Q.push(start);
        dist[start]=0;
        inQ[start]=1;
        while(Q.size()>0){
            auto cur = Q.front();
            Q.pop();
            for(auto x:adjList[cur]){
                if(!inQ[x]){
                    Q.push(x);
                    inQ[x]=1;
                    dist[x]=1+dist[cur];
                }
            }
        }
        if(dist.find(end) == dist.end()) return -1; 
        
        return dist[end];
    }
};