class Solution {
public:
    int dp[5005][7][20];
    const int MOD = 1e9+7;
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof dp);
        return count(0,n,0,0,rollMax);
    }
    int count(int idx,int n,int last,int trail,vector<int>& rollMax){
        if(idx>=n){
            return 1;
        }
        if(dp[idx][last][trail]!=-1){
            return dp[idx][last][trail];
        }
        int result=0;
        for(int i=1;i<=6;i++){
            if(i!=last){
                result += count(idx+1,n,i,1,rollMax);
                result %= MOD;
            }else{
                if(trail+1<=rollMax[i-1]){
                    result += count(idx+1,n,i,trail+1,rollMax);
                    result %= MOD;
                }
            }
        }
        return dp[idx][last][trail]=result;
    }
};