class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[i] = -1;            
        }
        vector<int> pref;
        pref.push_back(0);
        map<int,int> idx;
        for(int i=0;i<nums.size();i++){
            pref.push_back(nums[i]+pref.back());
            idx[pref.back()]=max(idx[pref.back()],i+1);
        }
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            int need = pref[i];
            if(idx.find(need)!=idx.end()){                
                res = max(res,idx[need]-i);
            }
        }
        return res;
    }
};