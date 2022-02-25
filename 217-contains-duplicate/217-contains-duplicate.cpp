class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> ss;
        for(int x:nums){
            if(ss.find(x)!=ss.end())return true;
            ss.insert(x);
        }
        return false;        
    }
};