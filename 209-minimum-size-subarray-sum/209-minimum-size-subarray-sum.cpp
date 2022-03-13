class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();        
        int result = INT_MAX;
        
        int i=0;
        int j=0;
        int sum = 0;
        while(i<n and j<n){            
            while(j<n and sum < target){
                sum += nums[j];
                j++;                
            }
            while(i<n and sum>=target){
                result = min(result,j-i);
                sum -= nums[i];
                i++;                
            }
        }    
        
        if(result == INT_MAX) result=0;
        return result;
    }
};