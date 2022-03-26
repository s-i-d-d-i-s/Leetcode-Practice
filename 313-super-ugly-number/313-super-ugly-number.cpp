#define ll long long
struct cmp{
    bool operator()(const pair<ll,pair<ll,ll>> &a,const pair<ll,pair<ll,ll>> &b) const{
        return a.first*a.second.second < b.first*b.second.second;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<ll> result={1};
        set<pair<ll,pair<ll,ll>>,cmp> pq;
        for(auto x:primes){
            pq.insert({x,{0,result[0]}}); // (prime,pointerToLastUglyNumber,lastUglyNumber)
        }
        while(result.size()<n){
            ll num = pq.begin()->first;
            ll pointer = pq.begin()->second.first;
            ll pointerValue = pq.begin()->second.second;
            
            ll value = num*pointerValue;
            
            pq.erase(pq.begin());
            result.push_back(value);
            
            while(true){
                pointer++;
                pair<ll,pair<ll,ll>> newEntry = {num,{pointer,result[pointer]}};
                if(pq.find(newEntry) == pq.end()){
                    pq.insert(newEntry);
                    break;
                }
            }
        }
        
        return result[n-1];
    }
};
