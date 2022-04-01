class Solution {
public:
    int dp[10005];
    int racecar(int target) {
        memset(dp,-1,sizeof dp);
        return solve(target);
    }
    
    int solve(int n){
        if(n==0) return 0;
        
       if(dp[n] != -1) return dp[n];
        
        int p2 = log(n+1);
        
        if((powl(2,p2) - 1) == n) return p2;
        
        // Go Ahead and Go Back
        int nextTarget = powl(2,p2+1)-1;
        
        int result1 = (p2+1) + 1 + solve(nextTarget-n);
        
        // Go Just Behind then Go Back
        for(int i=0;i<p2;i++){
            // Go jus behind
            int currentPos = powl(2,p2)-1;            
            int result2=p2;
            
            // Reverse
            result2++;
            
            // Go back
            int goneBack = powl(2,i)-1; // Distance gone back
            currentPos -= goneBack;// Change position
            result2 += i; // update steps
            
            // reverse
            result2++;            
            result2+=solve(n-currentPos);
            
            result1 = min(result1,result2);
        }
        return dp[n] = result1;
    }
        
    int log(int n){
        return log2l(n);
    }
    int safeDistance(int n){
        return powl(2,log(n))-1;
    }
};