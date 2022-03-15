class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int n = s.length();
        int i=0;
        int j=0;
        int result=0;
        while(j<n){
            freq[s[j]]++;
            j++;
            while(!valid(freq,k)){
                freq[s[i]]--;
                i++;
            }
            result = max(result,j-i);
        }
        return result;
    }
    
    bool valid(unordered_map<char,int> &freq,int k){
        int total = 0;
        int maxi = 0;
        for (auto x:freq){
            total += x.second;
            maxi = max(maxi,x.second);
        }
        return total-maxi <= k;
    }
};