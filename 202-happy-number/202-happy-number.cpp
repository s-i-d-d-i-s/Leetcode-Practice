class Solution {
public:
    map<int,int> visit;
    bool isHappy(int n) {
        if(n==1)return true;
        if(visit[n]){
            return false;
        }
        visit[n]=true;
        int res=0;
        while(n>0) res+=((n%10)*(n%10)),n/=10;
        return isHappy(res);
    }
};