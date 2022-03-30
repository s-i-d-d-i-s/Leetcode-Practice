class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hSet;
        for(int x:nums){
            hSet.insert(x);
        }
        if(hSet.find(0) == hSet.end()){
            nums.push_back(0);
            hSet.insert(0);
        }
        long long result=INT_MAX;
        for(long long x:nums){
            long long prev=x-1;
            long long next=x+1;
            if(prev>0 and hSet.find(prev) == hSet.end()){
                result = min(result,prev);
            }
            if(next>0 and hSet.find(next) == hSet.end()){
                result = min(result,next);
            }
        }
        return result;
    }
};