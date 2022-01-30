class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a;
        k%=nums.size();
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[ (i-k+nums.size())%nums.size() ]);
        }
        nums=a;
    }
};