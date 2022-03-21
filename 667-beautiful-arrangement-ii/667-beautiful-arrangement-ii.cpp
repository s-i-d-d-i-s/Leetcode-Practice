class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> a(n,-1);
        set<int> nums;
        for(int i=2;i<=n;i++)
            nums.insert(i);
        int diff=k;
        a[0]=1;
        for(int i=1;i<n and k>0;i++){
            int last = a[i-1];
            if(i&1){
                int next = last+k;
                nums.erase(next);
                a[i]=next;
            }else{
                int next = last-k;
                nums.erase(next);
                a[i]=next;
            }
            k--;
        }
        for(int i=0;i<n;i++){
            if(a[i]==-1){
                int next = *nums.begin();
                nums.erase(next);
                a[i]=next;
            }
        }
        return a;
    }
    
};