struct cmp{
  bool operator()(const pair<int,int> &a,const pair<int,int> &b) const{
      if(a.first == b.first)
          return a.second < b.second;
      return a.first < b.first;
  }  
};
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        multiset<pair<long long,long long>,cmp> ms;
        long long sum=0;
        ms.insert({0,0});
        long long result = INT_MAX;
        
        for(long long i=0;i<n;i++){
            sum += nums[i];
            if(sum>=k){
                result = min(result,i+1);
            }
            long long neededValue = sum - k;
            
            
            while(ms.size()>0){
                auto it=ms.begin();
                auto [pl,j] = *(it);
                if(pl>neededValue)break;
                ms.erase(it);  
                result = min(result,i+1-j);
            }
            ms.insert({sum,i+1});
        }
        if(result == INT_MAX) return -1;
        return result;
    }
};

/*
1 based

pref[r] - pref[l-1] >= k

pref[r] - k >= pref[l-1]
*/
