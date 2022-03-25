class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        auto foo = getMaxSumOfWindowK(nums,firstLen);
        return max(solve(nums,firstLen,secondLen),solve(nums,secondLen,firstLen));
    }
    int solve(vector<int>& nums, int firstLen, int secondLen) {
        int n =nums.size();
        
        vector<int> left = getMaxSumOfWindowK(nums,firstLen);
        reverse(nums.begin(),nums.end());
        
        vector<int> right = getMaxSumOfWindowK(nums,secondLen);
        reverse(nums.begin(),nums.end());
        reverse(right.begin(),right.end());
        
        int result = 0;
        for(int i=0;i<n-1;i++){
            int maxSumOnLeft = left[i];
            int maxSumOnRight = right[i+1];
            if(maxSumOnLeft == INT_MIN or maxSumOnRight == INT_MIN) continue;
            result = max(result,maxSumOnLeft+maxSumOnRight);
        }
        return result;
    }
    vector<int> getMaxSumOfWindowK(vector<int> &nums,int k){
        int n =nums.size();
        vector<int> result(n,INT_MIN);
        int cur=0;
        for(int i=0;i<k;i++) cur += nums[i];
        result[k-1]=cur;
        
        for(int i=k;i<n;i++){
            cur -= nums[i-k];
            cur += nums[i];
            result[i] = max(cur,result[i-1]);
        }
        return result;
    }
    
};