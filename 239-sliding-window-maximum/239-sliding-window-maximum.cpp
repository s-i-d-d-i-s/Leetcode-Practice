class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        map<int,int> freq;
        
        for(int i=0;i<k;i++){
            freq[nums[i]]++;
        }
        
        result.push_back( (--freq.end())->first );
        for(int i=k;i<n;i++){
            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0)freq.erase(nums[i-k]);
            freq[nums[i]]++;
            result.push_back( (--freq.end())->first );
        }
        return result;
    }
};