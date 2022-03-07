class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources,
                             vector<string>& targets) {
        
        vector<pair<int,pair<string,string>>> v;
        for(int i=0;i<indices.size();i++){
            v.push_back({indices[i],{sources[i],targets[i]}});
        }
        sort(v.begin(),v.end());
        
        for(int i=v.size()-1;i>=0;i--){
            string currentSource = v[i].second.first;
            string currentTarget = v[i].second.second;
            int currentIndex = v[i].first;
            if(s.substr(currentIndex,currentSource.length()) == currentSource ){                
                int idx = s.find(currentSource,currentIndex);
                s=s.replace(idx,currentSource.length(),currentTarget);
            }            
        }
        return s;
    }
};