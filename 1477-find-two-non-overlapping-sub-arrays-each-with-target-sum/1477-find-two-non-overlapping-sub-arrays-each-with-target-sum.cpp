class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n,INT_MAX),suff;
        int i=0,j=0,sum=0;
        while(j<n){
            sum+=arr[j];
            j++;
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            if(sum == target){
                best[i]=j-i;
            }
        }
        suff=best;
        for(int i=(int)suff.size()-2;i>=0;i--){
            suff[i] = min(suff[i],suff[i+1]);
        }
        int result=INT_MAX;
        for(int i=0;i<n;i++){
            if(best[i]!=INT_MAX){
                int l=i;
                int r=i+best[i]-1;
                if(r+1<n and suff[r+1]!=INT_MAX)
                    result = min(result,best[i]+suff[r+1]);
                    //cout << l << " " << r << " " << suff[r+1] << endl;
            }
        }
        if(result == INT_MAX) result = -1;
        return result;
    }
};