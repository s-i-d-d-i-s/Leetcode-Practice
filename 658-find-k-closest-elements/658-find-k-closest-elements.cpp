class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0;
        int r=arr.size()-1;
        int toRemove = arr.size()-k;
        while(l<=r and toRemove>0){
            int d1 = abs(x-arr[l]);
            int d2 = abs(x-arr[r]);
            if(d1<=d2){
                r--;
                toRemove--;
            }else{
                l++;
                toRemove--;
            }
        }
        vector<int> result;
        for(int i=l;i<=r;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};