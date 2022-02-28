class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string recur = countAndSay(n-1);
        string res="";
        int count=0;
        char last = '*';
        for(char x:recur){
            if(x!=last){
                if(count>0){
                    res+= to_string(count);
                    res+= last;
                }
                last=x;
                count=1;
            }else{
                count++;
            }
        }
        if(count>0){
            res+= to_string(count);
            res+= last;
        }
        return res;
    }
};