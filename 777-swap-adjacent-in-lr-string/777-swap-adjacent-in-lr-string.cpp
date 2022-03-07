class Solution {
public:
    int getNextValidIndex(string &a,int startIndex){
        for(int i=startIndex+1;i<a.length();i++){
            if(a[i]!='X') return i;
        }
        return -1;
    }
    bool canTransform(string start, string end) {
        int pt1 = getNextValidIndex(start,-1);
        int pt2 = getNextValidIndex(end,-1);
        
        while(pt1<start.length() and pt2<end.length() and pt1!=-1 and pt2!=-1){
            
            if(start[pt1] != end[pt2]) return false;
            if(start[pt1]=='R'){
                if(pt1>pt2)return false;
            }else{
                if(pt1<pt2)return false;
            }
            pt1 = getNextValidIndex(start,pt1);
            pt2 = getNextValidIndex(end,pt2);
        }
        return pt1==-1 and pt2==-1;
    }
};