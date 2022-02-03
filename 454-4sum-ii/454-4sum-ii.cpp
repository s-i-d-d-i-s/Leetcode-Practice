class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> foo;
        for(int x:nums3)
            for(int y:nums4){
                int sum = x+y;
                foo[sum]++;
            }
            
        
        int res=0;
        for(int x:nums1)
            for(int y:nums2){
                int sum = x+y;
                if(foo.find(-sum) == foo.end())
                    continue;                
                res += foo[-sum];
            }
        
        return res;
    }
};