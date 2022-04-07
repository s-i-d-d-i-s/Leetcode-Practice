class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> ms(stones.begin(),stones.end());
        while(ms.size()>=2){
            auto it = ms.end();
            it--;
            auto it2 = it;
            it2--;
            int n1 = *it;
            int n2 = *it2;
            ms.erase(it);
            ms.erase(it2);
            if(n1 == n2)
                continue;
            ms.insert(n1-n2);
        }
        if(ms.size()==0)return 0;
        return *ms.begin();
    }
};