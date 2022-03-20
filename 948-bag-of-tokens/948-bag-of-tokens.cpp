class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start=0;
        int end=tokens.size()-1;
        int score=0;
        
        int result=0;
        while(start<=end){
            if(power>=tokens[start]){
                power -= tokens[start];
                score++;
                start++;
            }else if(score>=1){
                score--;
                power += tokens[end];
                end--;
            }else{
                break;   
            }
            result=max(result,score);
        }
        
        return result;
    }
};