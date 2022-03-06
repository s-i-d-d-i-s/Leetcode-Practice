class Solution {
public:
    int getNextClosingBracket(string &s,int idx){
        int bal=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[')bal++;
            else if(s[i]==']'){
                bal--;
                if(bal==0)return i;
            }else{
                
            }
        }
        return -1;
    }
    string decodeString(string s) {
        if(s.length()==0)return "";
        int firstDigit=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' and s[i]<='9'){
                firstDigit=i;
                break;
            }
        }
        if(firstDigit == -1) return s;
        string result=s.substr(0,firstDigit);
        s=s.substr(firstDigit);
            
        int firstOpeningBracket = s.find('[');

        string kStr = s.substr(0,firstOpeningBracket);
        int k = stoi(kStr);

        int firstClosingBracket = getNextClosingBracket(s,firstOpeningBracket);
        int lenOfSubproblem = firstClosingBracket-firstOpeningBracket+1;

        string subProblem = s.substr(firstOpeningBracket+1,lenOfSubproblem-2);
        string decodedSubproblem = decodeString(subProblem);

        
        while(k--){
            result+=decodedSubproblem;
        }
        s=s.substr(firstClosingBracket+1);
        return result+decodeString(s);
        
        return s;        
    }
};