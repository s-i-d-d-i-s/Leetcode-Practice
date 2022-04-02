class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> line(101);
        for(auto x:clips){
            line[x[0]]=max(line[x[0]],x[1]);
        }
        int result=1;
        int canGo=line[0];
        int going=line[0];
        int pos=0;
        while(pos<time){
            canGo = max(canGo,line[pos]);
            if(going==pos){
                result++;
                if(going == canGo)break;
                going = canGo;                
            }
            pos++;
        }
        if(pos < time) return -1;
        return result;
    }
};