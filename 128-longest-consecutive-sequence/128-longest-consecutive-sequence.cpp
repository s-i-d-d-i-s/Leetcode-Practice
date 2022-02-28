class Solution {
public:
    unordered_set<int> hSet;
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;

        for(int x:nums) hSet.insert(x);
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(hSet.find(nums[i]-1) == hSet.end()){
                int current = 1;
                int number = nums[i]+1;
                while(hSet.find(number) != hSet.end()){
                    number++;
                    current++;
                }
                res = max(res,current);
            }
        }
        return res;
    }
};