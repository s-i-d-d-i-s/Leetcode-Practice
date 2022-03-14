class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto x:nums){
            freq[x]++;
        }
        vector<vector<int>> bucket(nums.size()+5);
        for(auto x:freq){
            bucket[x.second].push_back(x.first);
        }
        vector<int> result;
        for(int i=bucket.size()-1;i>=0;i--){
            for(int x:bucket[i]){
                if(result.size()<k){
                    result.push_back(x);
                }
            }
        }
        return result;
    }
};