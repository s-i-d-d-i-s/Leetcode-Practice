class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(),nums.end());
        int result=0;
        while(ms.size()>0){
            int smallest = *ms.begin();
            ms.erase(ms.begin());
            int need = k-smallest;
            if(ms.find(need) != ms.end()){
                ms.erase(ms.find(need));
                result++;
            }
        }
        return result;
    }
};