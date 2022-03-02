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
        
        // left  ->  [1] 2 3
        // right ->  [1] 3
        
        /*
            i = left pointer
            j = right pointer
            
            move pointer on right as long as its valid... that's the solution for that particular             'i'
            
            now when we move to the next 'i', we won't change 'j' 
            
            because for those numbers behind 'j', thier double was smaller than the previos 'i'
            
            and the previous i had a smaller value than now. so automatically, those values are 
            satisfied.
        */
        
        
        sort(a.begin()+l,a.begin()+r+1);
        return result;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};