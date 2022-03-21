class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int evenMoves=0,oddMoves=0;
        for(int i=0;i<n;i++){
            if(i&1){
                int left = i-1>=0?nums[i-1]:INT_MAX;
                int right = i+1<n?nums[i+1]:INT_MAX;
                
                int minValue = min(left,right);
                minValue--;
                evenMoves += (max(0,nums[i]-minValue));
            }else{
                int left = i-1>=0?nums[i-1]:INT_MAX;
                int right = i+1<n?nums[i+1]:INT_MAX;
                
                int minValue = min(left,right);
                minValue--;
                oddMoves += (max(0,nums[i]-minValue));
            }
        }
        return min(evenMoves,oddMoves);
    }
    
};