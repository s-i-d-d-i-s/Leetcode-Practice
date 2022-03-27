class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        int dp[n][2];
        
        dp[n-1][0]=true; // Go Up
        dp[n-1][1]=true; // Go Down
        map<int,int> idx;
        idx[arr[n-1]]=n-1;
        
        for(int i=n-2;i>=0;i--){
            int num = arr[i];
            dp[i][0]  = false;
            dp[i][1]  = false;
            if(idx.find(num) != idx.end()){
                int next = idx[num];
                cout << next << endl;
                dp[i][0]  = dp[next][1];
                dp[i][1]  = dp[next][0];
                idx[num]=i;
                continue;
            }
            auto it = idx.upper_bound(num);
            if(it != idx.end()){
                int go_up = it->second;
                dp[i][0] = dp[go_up][1];
            }
            if(it!=idx.begin()){
                it--;
                int go_down = it->second;
                dp[i][1] = dp[go_down][0];
            }
            idx[num]=i;
        }
        int result=0;
        for(int i=0;i<n;i++){
            cout << dp[i][0] << " " << dp[i][1] << endl;
            result += (dp[i][0]);
        }
        return result;
    }
};