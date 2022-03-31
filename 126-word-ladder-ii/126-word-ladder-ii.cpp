class Solution {
public:
    set<vector<string>> result;
    map<string,vector<string>> adj;
    
    bool hasEdge(string &a,string &b){
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                cnt++;
            }
            if(cnt>1)return false;
        }
        return cnt==1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(hasEdge(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(int i=0;i<wordList.size();i++){
            if(hasEdge(beginWord,wordList[i])){
                adj[wordList[i]].push_back(beginWord);
                adj[beginWord].push_back(wordList[i]);
            }
        }
        auto wordLength = ladderLength(beginWord,endWord,wordList);
        map<string,int> visit;
        vector<string> path;
        dfs(beginWord,endWord,path,visit,wordLength);
        return {result.begin(),result.end()};
    }
    
    void dfs(string &src,string &target,vector<string> &path,map<string,int> &visit,
             map<string,int> &wordLength){
        
        if(path.size() >= wordLength[src]) return;
        
        if(src == target){
            path.push_back(target);
            if(result.size()==0){
                result.insert(path);
            }else{
                if(path.size() < (*result.begin()).size()){
                    result.clear();
                    result.insert(path);
                }else if(path.size() == (*result.begin()).size()){
                    result.insert(path);
                }                
            }
            path.pop_back();
            return;
        }
        visit[src]=true;
        path.push_back(src);
        for(auto x:adj[src]){
            if(!visit[x]){
                dfs(x,target,path,visit,wordLength);
            }
        }
        visit[src]=false;
        path.pop_back();
    }
    
    
    map<string,int> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> adj;
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(hasEdge(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(int i=0;i<wordList.size();i++){
            if(hasEdge(beginWord,wordList[i])){
                adj[wordList[i]].push_back(beginWord);
                adj[beginWord].push_back(wordList[i]);
            }
        }
        map<string,int> visit,dist;
        queue<string> Q;
        Q.push(beginWord);
        dist[beginWord]=1;
        visit[beginWord]=0;
        while(Q.size()>0){
            auto cur = Q.front();
            Q.pop();
            for(auto x:adj[cur]){
                if(!visit[x]){
                    Q.push(x);
                    visit[x]=1;
                    if(dist.find(x)==dist.end())
                        dist[x]=dist[cur]+1;
                    else
                        dist[x]=min(dist[x],dist[cur]+1);
                }
            }
        }
        return dist;
    }
    
};