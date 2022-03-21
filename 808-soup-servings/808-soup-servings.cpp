#define N 4001
class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;
    vector<pair<int,int>> servings = {{100,0},{75,25},{50,50},{25,75}};
    double soupServings(int n) {
        if(n>=N) return 1;
        return solve(n,n);
    }
    
    double solve(int a,int b){
        if(a==0 and b==0) return 0.5;
        if(a==0) return 1;
        if(b==0) return 0;
        double result=0;
        if(dp[a][b] != 0){
            return dp[a][b];
        }
        for(auto x:servings){
            auto [sa,sb] = x;
            result += solve(max(0,a-sa),max(0,b-sb));
        }
        return dp[a][b]= result * 0.25;
    }
};