class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        
        map<string,vector<pair<string,double>>> adjList;
        for(int i=0;i<equations.size();i++){
            string eq1 = equations[i][0];
            string eq2 = equations[i][1];
            double value = values[i];
            adjList[eq1].push_back({eq2,value});
            adjList[eq2].push_back({eq1,1/value});
        }
        vector<double> result;
        for(int i=0;i<queries.size();i++){
            string eq1 = queries[i][0];
            string eq2 = queries[i][1];
            map<string,bool> visited;
            double sol=1;
            if(adjList.find(eq1) != adjList.end() and 
               depthFirstSearch(eq1,eq2,adjList,visited,sol)){
                result.push_back(sol);
            }else{
                result.push_back(-1);
            }
        }
        return result;
    }
    
    bool depthFirstSearch(string &a,string &b,map<string,vector<pair<string,double>>> &adjList,
                            map<string,bool> &visited,double &sol){
        if(a==b)return true;    
        visited[a] = true;
        double result=INT_MAX;
        for(auto x:adjList[a]){
            if(!visited[x.first]){
                double originalSol = sol;
                sol*=x.second;
                if(depthFirstSearch(x.first,b,adjList,visited,sol))return true;
                sol=originalSol;
            }
        }
        return false;
    }
};