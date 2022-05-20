class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int last=0;
        int n = nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            ms.insert(nums[i]);
            while(!isValid(ms,limit) and last<=i){
                ms.erase(ms.find(nums[last]));
                last++;
            }
            result = max(result,(int)ms.size());
        }
        return result;
    }
    
    bool isValid(multiset<int> &ms,int limit){
        if(ms.size()==0)return true;
        int first = *ms.begin();
        int last = *(--ms.end());
        return last-first <= limit;
    }
};