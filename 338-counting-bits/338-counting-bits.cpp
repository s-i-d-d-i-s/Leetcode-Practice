class Solution {
public:
    
    int getBitCount(int n){
        int res=0; // Solution
        while(n>0){
            if((n&1) == 1){
                res++;
            }
            n = n>>1;
        }
        return res;
    }
    
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        for(int i=0;i<=n;i++){
            result[i] = getBitCount(i);
        }
        return result;
    }
};