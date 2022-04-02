class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> freq((1<<16)+5);
        for(auto x:nums){
            for(auto y:nums){
                freq[x&y]++;
            }            
        }
        int result=0;
        for(auto x:nums){
            for(int i=0;i<freq.size();i++){
                if( (i&x) == 0)
                    result += freq[i];
            }
        }
        return result;
    }
};