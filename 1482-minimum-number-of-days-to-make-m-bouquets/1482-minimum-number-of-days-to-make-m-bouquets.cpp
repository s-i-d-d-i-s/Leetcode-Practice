class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int limit = *max_element(bloomDay.begin(),bloomDay.end())+5;
        int l=0;
        int r=limit;
        int result=r;
        while(l<=r){
            int mid = (l+r)/2;
            bool f = canForm(bloomDay,m,k,mid);
            if(f){
                result = min(result,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(result==limit)result=-1;
        return result;
    }
    bool canForm(vector<int> &bloom,int m,int k,int date){
        int current=0;
        for(int i=0;i<bloom.size();i++){
            if(date>=bloom[i]){
                current++;
            }else{
                current=0;
            }
            if(current>=k){
                m--;
                current=0;
            }
        }        
        return m<=0;
    }
};