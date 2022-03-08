class Solution {
public:
    
    bool canFormChain(string &a,string &b){
        if(a.length()+1 == b.length()){
            int i=0,j=0;
            while(i<a.length() and j<b.length()){
                if(a[i] == b[j]){
                    i++;
                    j++;
                }else{
                    j++;
                }
            }
            return i==a.length();
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string &a,string &b){
           return a.length() < b.length(); 
        });
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int maximum=0;            
            for(int j=i-1;j>=0;j--){
                if(canFormChain(words[j],words[i]))
                    maximum = max(maximum,dp[j]);
            }
            dp[i]=1+maximum;
        }
        return *max_element(dp.begin(),dp.end());
    }
};