class Solution {
public:
    bool isSelfCrossing(vector<int>& a) {
        int n = a.size();
        
        for(int i=0;i<n;i++){
            if(i+3<n){
                if(a[i+2]<=a[i] and a[i+1]<=a[i+3]) return true;
            }
            if(i+5<n){
                int openGapVertical = abs(a[i]-a[i+2]);
                int openGapHorizontal = abs(a[i+1]-a[i+3]);
                if(a[i+2]>a[i] and a[i+1]<a[i+3] and a[i+4]>=openGapVertical and a[i+4]<=(openGapVertical+a[i]) 
                   and a[i+5]>=openGapHorizontal){
                    return true;
                }
            }
            if(i+4<n){
                int openGapVertical = abs(a[i]-a[i+2]);
                int openGapHorizontal = abs(a[i+1]-a[i+3]);
                if(a[i+2]>a[i] and a[i+1]==a[i+3] and a[i+4]>=openGapVertical)
                    return true;
            }
        }
        return false;
    }
};