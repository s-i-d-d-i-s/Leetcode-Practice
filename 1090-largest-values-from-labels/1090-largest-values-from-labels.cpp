class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        multiset<pair<int,int>> ms;
        for(int i=0;i<values.size();i++){
            ms.insert({values[i],labels[i]});
        }
        
        unordered_map<int,int> freq;
        int result=0;
        int added=0;
        while(ms.size()>0 and added<numWanted){
            auto it = ms.end();
            it--;
            auto [val,lab]= *it;
            ms.erase(it);
            if(freq[lab] < useLimit){
                result+=val;
                freq[lab]++;
                added++;
            }
        }
        return result;
    }
};