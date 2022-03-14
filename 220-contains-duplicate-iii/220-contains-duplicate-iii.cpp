class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> ms;
        k++;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                if(check(ms,t,nums[i])){
                    return true;
                }
                ms.insert(nums[i]);
            }else{
                ms.erase(ms.find(nums[i-k]));
                if(check(ms,t,nums[i])){
                    return true;
                }
                ms.insert(nums[i]);
            }
            //cout << i << endl;
        }
        return false;
    }
    
    bool check(multiset<long long> &ms,long long t,long long num){
        long long r=t+num;
        long long l=num-t;
        //cout << t << " " << num << " " << l << " " << r << endl;
        auto it = ms.upper_bound(r);
        if(it == ms.begin())return false;
        it--;
        return *it>=l;
    }
};