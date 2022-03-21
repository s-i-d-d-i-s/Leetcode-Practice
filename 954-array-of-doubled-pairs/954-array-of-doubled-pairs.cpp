class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        vector<int> pos,neg;
        int zero=0;
        for(int x:arr){
            if(x>0){
                pos.push_back(x);
            }else if(x<0){
                neg.push_back(-x);
            }else{
                zero++;
            }
        }
        return isValid(pos) && isValid(neg) && zero%2==0;
    }
    bool isValid(vector<int> &arr){
        multiset<int> ms(arr.begin(),arr.end());
        while(ms.size()>0){
            auto num = *ms.begin();
            ms.erase(ms.begin());
            if(ms.find(2*num) != ms.end()){
                ms.erase(ms.find(2*num));
            }else{
                return false;
            }
        }
        return true;
    }
};