class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        
        /*
            0 1 3 5 6
        */
        int cnt=0;
        int result=0;
        for(int j=n-1;j>=0;j--){
            cnt++;
            if(citations[j] >= cnt){
                result = max(result,cnt);
            }
        }
        return result;
    }
};