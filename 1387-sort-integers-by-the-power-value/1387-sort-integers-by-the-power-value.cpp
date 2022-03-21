class Solution {
public:
    unordered_map<int,int> dp;
    int getKth(int lo, int hi, int k) {

        vector<int> nums;
        for(int i=lo;i<=hi;i++){
            nums.push_back(i);
            getPower(i);
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(dp[a] == dp[b]){
               return a<b;
            } 
            return dp[a]<dp[b];
        });
        return nums[k-1];
    }
    int getPower(int n){
        if(n==1) return 0;
        if(dp.count(n))
            return dp[n];        
        if(n%2 == 0) return dp[n]=1+getPower(n/2);      
        return dp[n]=1+getPower(3*n + 1);
    }
};