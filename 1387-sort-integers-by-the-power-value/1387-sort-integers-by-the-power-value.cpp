class Solution {
public:
    int dp[1005];
    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for(int i=lo;i<=hi;i++){
            nums.push_back(i);
            int result=0;
            int num=i;
            while(num != 1){
                if(num & 1) num = 3*num+1;
                else num/=2;
                result++;
            }
            dp[i]=result;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(dp[a] == dp[b]){
               return a<b;
            } 
            return dp[a]<dp[b];
        });
        return nums[k-1];
    }

};