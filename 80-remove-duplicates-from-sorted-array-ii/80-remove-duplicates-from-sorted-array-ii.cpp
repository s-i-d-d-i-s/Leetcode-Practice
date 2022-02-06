class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int pt=-1;
        int num=-1;
        int cnt=0;
        int result=0;
        for(int i=0;i<a.size();i++){
            if(num == a[i]){
                cnt++;
            }else{
                num = a[i];
                cnt = 1;                
            }
            if(cnt <= 2){
                pt++;
                swap(a[pt],a[i]);
                result++;
            }
        }
        return result;
    }
};