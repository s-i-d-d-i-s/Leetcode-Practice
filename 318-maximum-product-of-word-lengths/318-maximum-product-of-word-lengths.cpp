class Solution {
public:
    int getBitMask(string &a){
        int result = 0;
        for(char x:a){
            int index = x-'a';
            result |= (1<<index);
        }
        return result;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int bitMasks[n];
        for(int i=0;i<n;i++){
            bitMasks[i] = getBitMask(words[i]);
        }
        
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( (bitMasks[i] & bitMasks[j]) == 0){
                    result = max(result,(int)(words[i].length()*words[j].length()));
                }
            }
        }
        return result;
    }
};