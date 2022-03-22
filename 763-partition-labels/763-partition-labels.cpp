class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> freqRight,freqLeft;
        for(char x:s){
            freqRight[x]++;
        }
        vector<int> result;
        for(int i=0;i<s.length();i++){
            freqRight[s[i]]--;
            freqLeft[s[i]]++;
            if(freqRight[s[i]] == 0) freqRight.erase(s[i]);
            if(isDisjoint(freqLeft,freqRight)){
                result.push_back(getSize(freqLeft));
                freqLeft.clear();
            }
        }
        return result;
    }
    
    bool isDisjoint(map<char,int> &a,map<char,int> &b){
        for(auto x:a)
            if(b.find(x.first) != b.end())
                return false;                    
        for(auto x:b)
            if(a.find(x.first) != a.end())
                return false;
        return true;        
    }
    int getSize(map<char,int> &a){
        int result=0;
        for(auto x:a)
            result += x.second;        
        return result;
    }
};