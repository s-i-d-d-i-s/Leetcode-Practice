class Solution {
public:
    int nextIndex=0;
    unordered_map<string,int> getIndex;
    
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        
        // Assign an index to all companies
        for(auto x:favoriteCompanies){
            for(auto y:x){
                if(getIndex.find(y) == getIndex.end()){
                    getIndex[y] = nextIndex++;
                }
            }
        }
        vector<bitset<50001>> bits;
        for(auto x:favoriteCompanies){
            bitset<50001> current;
            for(auto y:x){
                int companyIndex = getIndex[y];
                current[companyIndex]=1;
            }
            bits.push_back(current);
        }
        int n = favoriteCompanies.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            bool isASubset = false;
            for(int j=0;j<n && !isASubset;j++){
                if(i!=j){
                    auto resultBits = bits[i]&bits[j];
                    if(resultBits == bits[i]){
                        isASubset = true;
                    }
                }
            }
            if(!isASubset){
                result.push_back(i);
            }
        }
        return result;
    }
};