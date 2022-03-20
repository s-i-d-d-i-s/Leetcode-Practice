class Solution {
public:
    unordered_map<char,int> freq;
    
    int numTilePossibilities(string tiles) {
        for(char x:tiles)
            freq[x]++;
        
        int result=0;        
        
        for(char i='A';i<='Z';i++){
            if(freq[i]>0){
                freq[i]--;
                result += countPermutation();
                freq[i]++;
            }
        }
        return result;
    }
    
    int countPermutation(){
        int result=1;
        for(char i='A';i<='Z';i++){
            if(freq[i]>0){
                freq[i]--;
                result += countPermutation();
                freq[i]++;
            }
        }
        return result;
    }
};