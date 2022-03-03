class Solution {
public:
     int getSubarrays(int n){
        n++;
        int res=0;
        for(int i=3;i<=n;i++){
            res += (n-i+1);
        }
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        int result = 0;
        
        vector<int> diff;
        for(int i=1;i<nums.size();i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        int last=INT_MIN;
        int count=0;        
        
        for(int i=0;i<diff.size();i++){
            if(diff[i] == last){
                count++;
            }else{
                result += getSubarrays(count);
                last = diff[i];
                count=1;
            }
        }
        
        if(count > 0){
            result += getSubarrays(count);
        }
        return result;
    }
};