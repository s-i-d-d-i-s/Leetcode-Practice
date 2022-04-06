class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        int n = a.size();
        int N=500;
        int res=0;
        for(int i=0;i<n;i++){
            vector<int> freq(N,0);
            for(int j=i+1;j<n;j++){
                freq[a[j]]++;
            }
            for(int j=i+1;j<n-1;j++){
                freq[a[j]]--;
                
                int need=target-a[i]-a[j];
                if(need<0 and need<N)continue;
                res += freq[need];
                res%=((int)(1e9+7));
            }
        }
        return res;
    }
};