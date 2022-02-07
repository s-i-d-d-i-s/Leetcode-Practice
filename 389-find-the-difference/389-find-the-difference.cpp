class Solution {
public:
    char findTheDifference(string s, string t) {
        map<int,int> freq;
        for(auto x:s) freq[x]++;
        for(auto x:t){
            freq[x]--;
            if(freq[x]==0)freq.erase(x);
        }
        return freq.begin()->first;
    }
};