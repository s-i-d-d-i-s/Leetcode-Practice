class Solution {
public:
    vector<int> result;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        result.resize(n);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        mergeSort(0,n-1,v);
        return result;
    }
    
    void mergeSort(int l,int r,vector<pair<int,int>> &v){
        if(l>=r)return;
        int m = (l+r)/2;
        mergeSort(l,m,v);
        mergeSort(m+1,r,v);
        
        int p1=l;
        int p2=m+1;
        
        int movedLeft=0;
        int movedRight=0;
        
        vector<int> invCount(r-l+1);
        
        
        // p1 -> left, p2-> right
        
        while(p1<=m and p2<=r){
            if(v[p1].first < v[p2].first){
                invCount[p1-l] = movedRight;
                movedLeft++;
                p1++;
            }else if(v[p1].first > v[p2].first){
                movedRight++;
                p2++;                
                invCount[p1-l] = movedRight;
            }else{
                invCount[p1-l] = movedRight;
                movedLeft++;
                p1++;
            }            
        }
        while(p1<=m){
            invCount[p1-l] = movedRight;
            p1++;
        }
        while(p2<=r){            
            p2++;
        }

        for(int i=0;i<invCount.size();i++){
            result[v[i+l].second]+=invCount[i];
        }
        sort(v.begin()+l,v.begin()+r+1);
        return;
    }
};
