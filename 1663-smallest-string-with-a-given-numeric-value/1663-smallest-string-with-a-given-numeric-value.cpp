class Solution {
public:

    string getSmallestString(int n, int k) {
        vector<int> chars(n,k/n);
        int rem = k%n;
        for(int i=n-1;i>=0 and rem-->0;i--){
            chars[i]++;
        }
        int l=0;
        int r=n-1;
        while(l<r){
            int extra_on_l = chars[l]-1;
            int can_have_on_r = 26-chars[r];
            int mini = min(extra_on_l,can_have_on_r);
            chars[l]-=mini;
            chars[r]+=mini;
            if(chars[l]==1){
                l++;
            }else{
                r--;
            }
        }
        string result="";
        for(int i=0;i<n;i++){
            result+=((chars[i]-1)+'a');
        }
        return result;
    }
};