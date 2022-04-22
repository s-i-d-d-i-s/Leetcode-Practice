class Solution {
public:
    bool judgeCircle(string moves) {
        int offsetHorizontal = 0;
        int offsetVertical = 0;
        for(auto x:moves){
            if(x=='U')offsetVertical++;
            else if(x=='D')offsetVertical--;
            else if(x=='L')offsetHorizontal++;
            else offsetHorizontal--;
        }
        return offsetHorizontal==0 and offsetVertical==0;
    }
};