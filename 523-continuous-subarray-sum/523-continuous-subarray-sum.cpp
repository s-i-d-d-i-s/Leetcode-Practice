class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n+1);
        pref[0]=0;
        unordered_map<int,int> hMap;
        hMap[pref[0]]=0;
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]+nums[i];
            pref[i+1] %= k;
            
            if(hMap.find(pref[i+1])!=hMap.end() and hMap[pref[i+1]]<i)return true;
            if(hMap.find(pref[i+1])==hMap.end())
                hMap[pref[i+1]]=i+1;
        }
        return false;
    }
};

  //   [1][1]
  // 0  1  2