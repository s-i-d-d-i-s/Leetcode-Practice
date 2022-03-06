class Solution {
public:
    int dp[501];
    int countOrders(int n) {
        dp[1]=1,dp[2]=6;
		for(int i=3;i<=n;i++){
			long long temp=0,t,u=2*i-1;
			temp=(temp%(1000000007)+(u))%(1000000007); //put it in space inbetween

			t=((2*i-2)*(2*i-1))/2%(1000000007);
			temp=(temp%(1000000007)+t%(1000000007))%(1000000007);
			dp[i]=(temp%(1000000007)*dp[i-1]%(1000000007))%(1000000007);
		}
		return dp[n];
    }
};