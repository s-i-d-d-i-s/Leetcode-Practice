class Solution {
public:
    string removeKdigits(string nums, int k) {
        string res;
        for(int i=0;i<nums.size();i++){
            if(res.size()==0 or nums[i]>=res.back()){
                res.push_back(nums[i]);
            }else{
                while(k>0 and res.size()>0 and res.back()>nums[i]){
                    k--;
                    res.pop_back();
                }
                res.push_back(nums[i]);
            }
        }
        while(k-->0){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        while(res.size()>0 and res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());   
        if(res.size() == 0){
            res = "0";
        }
        return res;
    }
};