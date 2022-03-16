class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> numbers;
        for(int i=1;i<=n;i++){
            numbers.push_back(i);
        }
        for(int i=0;i<powl(2,n);i++){
            int mask=i;
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(mask & 1){
                    temp.push_back(numbers[j]);
                }
                mask/=2;
            }
            if(temp.size()==k){
                result.push_back(temp);
            }
        }
        return result;
    }
};