class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt;
        alt.push_back(0);
        for(int x:gain){
            alt.push_back(alt.back()+x);
        }
        return *max_element(alt.begin(),alt.end());
    }
};