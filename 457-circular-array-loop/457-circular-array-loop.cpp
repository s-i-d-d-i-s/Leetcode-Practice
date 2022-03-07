class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> colours(n,0);
        for(int i=0;i<n;i++){
            if(colours[i] == 0 and depthFirstSearch(i,nums,colours))return true;
        }
        return false;
    }
    bool depthFirstSearch(int source,vector<int> &nums,vector<int> &colours){
        if(colours[source] == 1)return true;
        if(colours[source] == 2)return false;
        
        colours[source]=1;
        
        int next = getNextIndex(source,nums);
        if(source == next or nums[source]*nums[next]<0){
            colours[source]=2;
            return false;
        }
                 
        if(depthFirstSearch(next,nums,colours))return true;
        
        colours[source]=2;
        return false;
    }
    
    int getNextIndex(int source,vector<int> &nums){
        int n = nums.size();
        int next= source + nums[source];
        if(next >=0 ){
            next %=n;
        }else{
            next+=n*1000;
            next%=n;
        }
        return next;
    }
};