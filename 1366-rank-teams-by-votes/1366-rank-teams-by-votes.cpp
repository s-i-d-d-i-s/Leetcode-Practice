class Solution {
public:
    unordered_map<char,vector<int>> participantScore;
    string rankTeams(vector<string>& votes) {
        
        
        for(auto x:votes)
            for(int i=0;i<x.length();i++)
                participantScore[x[i]].push_back(i);
            
        
        for(auto x:participantScore)
            sort(participantScore[x.first].begin(),participantScore[x.first].end());
        
        
        string result = votes[0];
        sort(result.begin(),result.end(),[&](char &a,char &b){
            if(participantScore[a]==participantScore[b]){
                return a<b;
            }
            return participantScore[a]<participantScore[b];
        });
        return result;
    }
};