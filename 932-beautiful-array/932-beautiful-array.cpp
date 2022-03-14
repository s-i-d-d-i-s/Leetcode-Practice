class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1){
            return vector<int>({1});
        }
        
        auto old= beautifulArray(n-1);
        vector<int> result;
        for(int x:old){
            int element = 2*x-1;
            if(element<=n){
                result.push_back(element);
            }
        }
        for(int x:old){
            int element = 2*x;
            if(element<=n){
                result.push_back(element);
            }
        }
        return result;
    }
};