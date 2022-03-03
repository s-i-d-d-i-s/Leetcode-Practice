class Solution {
public:
    int sum(int m,int n){
        return n*m-(n*(n+1))/2 + n;
    }
    int getSubarrays(int n){
        n++;
        if(n<3)return 0;        
        int res= sum(n,n) - sum(n,2);
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        
        int result = 0;
        
        vector<int> diff;
        for(int i=1;i<nums.size();i++)
            diff.push_back(nums[i]-nums[i-1]);
        
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
        
        if(count > 0)
            result += getSubarrays(count);
        
        return result;
    }
};