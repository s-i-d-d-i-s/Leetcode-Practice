class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums,0,nums.size()-1,true);
    }
    bool canWin(vector<int>& nums,int l,int r,bool isTurnForA,int score=0){
        if(l>r){
            if(isTurnForA){
                return score>=0;
            }
            return score<0;
        }
        // Choose from the left
        bool outcome_1 = canWin(nums,l+1,r,isTurnForA^1,score+(isTurnForA?nums[l]:-nums[l]));
        bool outcome_2 = canWin(nums,l,r-1,isTurnForA^1,score+(isTurnForA?nums[r]:-nums[r]));
        
        return !outcome_1 or !outcome_2;
    }
};