class Solution {
public:
    map<string,multiset<string>> adjList;
    map<pair<string,string>,int> freq;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x:tickets){
            adjList[x[0]].insert(x[1]);
            freq[{x[0],x[1]}]++;
        }
        vector<string> path;
        int count = tickets.size();
        depthFirstSearch("JFK",path,count);
        return path;
    }
    
    bool depthFirstSearch(string source,vector<string> &path,int count){
        
        bool isTerminal=true;
        path.push_back(source);
        for(auto x:adjList[source]){
            if(freq[{source,x}]>0){
                freq[{source,x}]--;
                isTerminal = false;
                if(depthFirstSearch(x,path,count-1)) return true;
                freq[{source,x}]++;
            }
        }
        if(isTerminal and count==0)
            return true;
        path.pop_back();
        return false;
    }
};