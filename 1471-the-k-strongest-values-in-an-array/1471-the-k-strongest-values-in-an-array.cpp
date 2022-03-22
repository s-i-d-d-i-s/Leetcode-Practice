class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n = a.size();
        
        int m = a[(n-1)/2];
        int l=0;
        int r=n-1;
        vector<int> result;
        while(l<=r and k--){
            if(abs(m-a[l])>abs(m-a[r])){
                result.push_back(a[l++]);
            }else if(abs(m-a[l])<abs(m-a[r])){
                result.push_back(a[r--]);
            }else{
                if(a[l]>a[r]){
                    result.push_back(a[l++]);
                }else{
                    result.push_back(a[r--]);
                }
            }
        }
        return result;
    }
};