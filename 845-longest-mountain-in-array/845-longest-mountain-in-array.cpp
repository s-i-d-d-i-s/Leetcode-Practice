class Solution {
public:
    int longestMountain(vector<int>& a) {
        int count=1;
        int result=0;       
        int n=a.size();
        
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i-1]){
                count++;
            }else{
                count=1;
            }
            if(a[i]>a[i-1] and a[i]>a[i+1]){
                // we are at a peak
                int j=i+1;
                int right = 0;
                while(j<n and a[j]<a[j-1]){
                    j++;
                    right++;
                }
                j--;
                result = max(result,count+right);
                i=j;
                count=1;
            }
        }
        return result;
    }
};