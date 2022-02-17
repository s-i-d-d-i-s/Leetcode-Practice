class Solution {
public:
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string trans(string &a){
        string res;
        for(auto x:a){
            res += morse[x-'a'];
        }
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> ss;
        for(auto x:words){
            ss.insert(trans(x));
        }
        return ss.size() ;
    }
};