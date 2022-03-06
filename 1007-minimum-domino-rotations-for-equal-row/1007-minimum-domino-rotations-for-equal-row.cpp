class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int> present,isUp,isDown;
        int n = tops.size();
        for(int i=0;i<n;i++){
            // Check if it is at least present in all n domino
            present[tops[i]]++;
            if(tops[i] != bottoms[i])
                present[bottoms[i]]++;
            
            // Count the occurance on top
            isUp[tops[i]]++;
            
            // Count the occurance on bottom
            isDown[bottoms[i]]++;
        }
        int result=n+1;
        for(auto x:present){
            if(x.second == n){ // Occurs in all domino cells
                
                // Flip the one on up or Flip the one on down
                result = min(result, min(n-isDown[x.first],n-isUp[x.first]));
            }
        }
        if(result == n+1) result=-1;
        return result;
    }
};