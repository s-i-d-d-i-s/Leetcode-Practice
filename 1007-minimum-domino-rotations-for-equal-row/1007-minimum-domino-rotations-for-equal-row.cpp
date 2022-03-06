class Solution {
public:
    
    int minRotation(vector<int>& tops, vector<int>& bottoms,int target){
        int make_top_equal = 0;
        int make_bottom_equal = 0;
        int n =  tops.size();
        for(int i=0;i<n;i++){
            if(tops[i] != target){
                make_top_equal++;
            }
            if(bottoms[i] != target){
                make_bottom_equal++;
            }
            if(tops[i]!= target and bottoms[i]!=target) return n+1;
        }
        return min(make_top_equal,make_bottom_equal);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n =  tops.size();
        int possible_sol_1 = tops[0];
        int possible_sol_2 = bottoms[0];
        int result = min(minRotation(tops,bottoms,possible_sol_1),minRotation(tops,bottoms,possible_sol_2));
        if(result == n+1) result=-1;
        return result;
    }
};