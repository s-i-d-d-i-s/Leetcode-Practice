class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pref[n+1];
        
        map<int,int> count;
        pref[0]=0;
        count[0]++;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
            count[pref[i+1]]++;
        }
        int res=0;
        for(int i=0;i<n;i++){
            count[pref[i]]--;
            res += count[k+pref[i]];
        }
            
        return res;
    }
};