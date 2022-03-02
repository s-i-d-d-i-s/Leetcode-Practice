class Solution {
public:
    int mergeSort(vector<int> &a,int l,int r){
        if(l>=r)return 0;
        int m = (l+r)/2;
        int result = mergeSort(a,l,m) + mergeSort(a,m+1,r);
        
        int p1=l;
        int p2=m+1;
        
        while(p1<=m){
            while(p2<=r){
                if((long)a[p1] > 2*(long)a[p2] )
                    p2++;
                else break;
            }
            result += p2 - (m+1);
            p1++;
        }
        
        sort(a.begin()+l,a.begin()+r+1);
        return result;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};