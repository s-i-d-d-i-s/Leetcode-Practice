class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        set<pair<int,int>> result;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]--;
            if(freq[nums[i]]==0){
                freq.erase(nums[i]);
            }
            if(freq.find(nums[i]-k) != freq.end()){
                pair<int,int> current = {nums[i]-k,nums[i]};
                result.insert(current);
            }
            if(freq.find(nums[i]+k) != freq.end()){
                pair<int,int> current = {nums[i],nums[i]+k};
                result.insert(current); 
            }
        }
        return result.size();
    }
};