class Solution {
public:
    unordered_map<char,int> index;
    string customSortString(string order, string s) {
        for(int i=0;i<order.size();i++){
            index[order[i]]=i;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            return index[a]<index[b];
        });
        return s;
    }
};