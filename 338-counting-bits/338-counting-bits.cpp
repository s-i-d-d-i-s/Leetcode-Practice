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
        vector<int> result(n+1,-1);
        for(int i=0;i<=n;i++){
            if(i==0)
                result[i] = getBitCount(i);
            else if(i%2 == 0)
                result[i] = result[i/2];
            else if(i%2 != 0)
                result[i] = 1+result[i-1];
                
        }
        return result;
    }
};