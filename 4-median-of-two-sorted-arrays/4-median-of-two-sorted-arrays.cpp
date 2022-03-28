class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n = nums1.size();
        int m = nums2.size();
        
        int l = 0;
        int r = nums1.size();
        
        while(l<=r){
            int cut1 = (l+r)/2;
            int medianSize = (n+m)%2==0 ? (n+m)/2 : (n+m)/2 + 1;            
            int cut2 = medianSize-cut1;
            
            int l1 = cut1-1>=0 ? nums1[cut1-1] : INT_MIN;
            int l2 = cut2-1>=0 ? nums2[cut2-1] : INT_MIN;
            
            int r1 = cut1<n ? nums1[cut1] : INT_MAX;
            int r2 = cut2<m ? nums2[cut2] : INT_MAX;
            
            if(l1<=r2 and l2<=r1){
                // Found the median
                if( (n+m) % 2 == 0 ){
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }else{
                    return max(l1,l2);
                }
            }else if(l1 > r2){
                r=cut1-1;
            }else{
                l=cut1+1;
            }
        }
        return -1;
    }
};
