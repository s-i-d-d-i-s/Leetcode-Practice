class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int n = fruits.size();
        int left=0;
        int result=0;
        for(int i=0;i<n;i++){
            freq[fruits[i]]++;
            while(freq.size() >= 3 and left<i){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            int currentFruits = 0;
            for(auto x:freq){
                currentFruits += x.second;
            }
            result = max(result,currentFruits);
        }
        return result;
    }
};