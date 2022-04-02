class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> lines(n+5);
        for(int i=0;i<ranges.size();i++){
            int l = i-ranges[i];
            int r = i+ranges[i];
            l=max(0,l);
            r=min(n,r);
            lines[l] = max(lines[l],r);
        }
        int result=1;
        int pos=0;
        int canGo = lines[0];
        int going = lines[0];
        while(pos<n){
            canGo = max(canGo,lines[pos]);
            if(going == pos){
                if(going == canGo)break;
                result++;
                going = canGo;
            }
            pos++;
        }
        if(pos < n ) return -1;
        return result;
    }
};