class TopVotedCandidate {
public:
    map<int,int> freq;
    vector<pair<int,int>> leaders;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int winner = persons[0];
        freq[persons[0]]++;
        leaders.push_back({times[0],winner});
        
        for(int i=1;i<persons.size();i++){
            if(persons[i]==winner){
                freq[winner]++;
                leaders.push_back({times[i],winner});
            }else{
                freq[persons[i]]++;                
                if(freq[persons[i]] >= freq[winner]){
                    winner=persons[i];
                }
                leaders.push_back({times[i],winner});
            }
        }        
    }
    
    int q(int t) {
        int result=-1;
        int l=0;
        int r=leaders.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(leaders[m].first > t){
                r=m-1;
            }else{
                result = leaders[m].second;
                l=m+1;
            }
        }
        return result;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */