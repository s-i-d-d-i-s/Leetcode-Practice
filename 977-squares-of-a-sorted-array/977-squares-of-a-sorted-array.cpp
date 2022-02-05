class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pt1=-1;
        
        for(int i=0;i<n;i++){
            if(nums[i]<0)
                pt1=i;            
        }
        int pt2=pt1+1;
        vector<int> res;
        while(pt2<n and pt1>=0){
            if(abs(nums[pt2]) < abs(nums[pt1]))
                res.push_back(nums[pt2++]);
            else
                res.push_back(nums[pt1--]);            
        }
        
        while(pt2<n)
            res.push_back(nums[pt2++]);
        
        
        while(pt1>=0)
            res.push_back(nums[pt1--]);
        
        for(int i=0;i<n;i++){
            res[i]*=res[i];
        }
        
        return res;
    }
};