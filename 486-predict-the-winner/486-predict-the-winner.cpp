class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums,0,nums.size()-1,true);
    }
    bool canWin(vector<int>& nums,int l,int r,bool isTurnForA,int scoreA=0,int scoreB=0){
        if(l>r){
            if(isTurnForA){
                return scoreA>=scoreB;
            }
            return scoreA<scoreB;
        }
        // Choose from the left
        bool outcome_1 = canWin(nums,l+1,r,isTurnForA^1,scoreA+(isTurnForA?nums[l]:0),scoreB + (!isTurnForA?nums[l]:0));
        bool outcome_2 = canWin(nums,l,r-1,isTurnForA^1,scoreA+(isTurnForA?nums[r]:0),scoreB + (!isTurnForA?nums[r]:0));
        
        return !outcome_1 or !outcome_2;
    }
};