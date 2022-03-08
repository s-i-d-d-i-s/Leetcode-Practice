class Solution {
public:
    long long getBitMask(string &a){
        long long result = 0;
        for(char x:a){
            int index = x-'a';
            result |= (1<<index);
        }
        return result;
    }
    
    int maxProduct(vector<string>& words) {
        vector<long long> bitMasks;
        for(auto x:words){
            bitMasks.push_back(getBitMask(x));
        }
        int n = words.size();
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