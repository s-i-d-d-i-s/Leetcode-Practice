bool isLow(char a){
    return a>='a' and a<='z';
}

class Solution {
public:
    int dp[101][101];
    bool check(int p1,int p2,string &a,string &b){
        if(p1>=a.length()){
            return p2>=b.length();
        }
        if(dp[p1][p2]!=-1){
            return dp[p1][p2];
        }
        if(p2>=b.length()){
            if(!isLow(a[p1])){
                return dp[p1][p2]=false;
            }
            return dp[p1][p2]=check(p1+1,p2,a,b);
        }
        if(a[p1] == b[p2]){
            return dp[p1][p2]=check(p1+1,p2+1,a,b);
        }else{
            if(!isLow(a[p1])){
                return dp[p1][p2]=false;
            }
            return dp[p1][p2]=check(p1+1,p2,a,b);
        }
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto x:queries){
            memset(dp,-1,sizeof dp);
            res.push_back(check(0,0,x,pattern));   
        }
        return res;
    }
};