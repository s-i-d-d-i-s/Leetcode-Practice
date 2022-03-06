class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int> freq,isUp,isDown;
        int n = tops.size();
        for(int i=0;i<n;i++){
            freq[tops[i]]++;
            isUp[tops[i]]++;
            isDown[bottoms[i]]++;
            if(tops[i] != bottoms[i])
                freq[bottoms[i]]++;
        }
        int result=n+1;
        for(auto x:freq){
            if(x.second == n){
                result = min(result, min(n-isDown[x.first],n-isUp[x.first]));
            }
        }
        if(result == n+1) result=-1;
        return result;
    }
};