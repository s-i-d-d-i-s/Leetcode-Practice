
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        map<char,int> freq1,freq2;
        for(auto x:s1){
            freq1[x]++;
        }
        for(int i=0;i<s1.length();i++){
            freq2[s2[i]]++;
        }
        if(freq1 == freq2)return true;
        for(int i=s1.length();i<s2.length();i++){
            freq2[s2[i-s1.length()]]--;
            if(freq2[s2[i-s1.length()]]==0){
                freq2.erase(s2[i-s1.length()]);
            }
            freq2[s2[i]]++;
            if(freq1 == freq2)return true;
        }
        return false;
    }
};