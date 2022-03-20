class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int result = 0 ;
        int n = people.size();
        int l = 0;
        int r = n-1;
        sort(people.begin(),people.end());
        while(l<=r){
            int cur = people[r]+people[l];
            if(cur <= limit){
                l++;
                r--;
            }else{
                r--;
            }
            result++;
        }
        return result;
    }
};