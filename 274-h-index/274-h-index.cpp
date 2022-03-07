class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        for(int i=0;i<=n;i++){
            int cnt=i;
            int cnt2=0;
            for(int j=n-1;j>=0;j--){
                if(cnt>0 and citations[j] >= i){
                    cnt--;
                }else if(citations[j] <= i){
                    cnt2++;
                }
            }
            if(cnt2+i == n and cnt==0){
                return i;
            }
        }
        return -1;
    }
};