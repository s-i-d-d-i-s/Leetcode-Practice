class Solution {
public:
    int getMin(map<int,int> &freq){
        return freq.begin()->first;
    }
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        while(freq.size()>0){
            int start = getMin(freq);
            int cnt=k;
            while(cnt>0){
                if(freq.find(start) != freq.end()){
                    freq[start]--;
                    if(freq[start]==0)freq.erase(start);
                    cnt--;
                    start++;
                }else{
                    break;
                }
            }
            if(cnt !=0 ) return false;
        }
        return true;
    }
};