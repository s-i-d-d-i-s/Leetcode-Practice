class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last=-1;
        int cnt=0;
        int res_num=0;
        int res_count=0;
        for(int x:nums){
            if(x!=last){
                if(cnt>res_count){
                    res_count = cnt;
                    res_num = last;
                }
                cnt=1;
                last=x;
            }else{
                cnt++;
            }
        }
        if(cnt>res_count){
            res_count = cnt;
            res_num = last;
        }
        return res_num;
    }
};