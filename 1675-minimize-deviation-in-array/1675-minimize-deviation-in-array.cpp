class Solution {
public:
    int getDeviation(multiset<int> &ms){
        auto it = ms.end();
        it--;
        return (*it) - (*ms.begin());
    }
    int minimumDeviation(vector<int>& nums) {
        multiset<int> ms;
        for(int x:nums){
            if(x&1)
                ms.insert(x*2);
            else
                ms.insert(x);            
        }
        int res=getDeviation(ms);
        // 2 6 4 10 20
        while(ms.size()>0){
            auto it = ms.end();
            it--;
            int num = *it;
            ms.erase(it);
            if(num%2==0){
                num/=2;
                ms.insert(num);
            }else{
                break;
            }
            int cur = getDeviation(ms);
            res = min(res,cur);
        }
        return res;
    }
};