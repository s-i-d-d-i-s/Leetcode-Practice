class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            int sum =  numbers[l]+numbers[r];
            if(sum == target){
                return {l+1,r+1};
                break;
            }else if(sum < target){
                l++;
            }else{
                r--;
            }
        }
        return result;
    }
};