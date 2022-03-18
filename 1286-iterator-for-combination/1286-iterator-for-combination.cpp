class CombinationIterator {
public:
    string characters,bitString;
    bool hasNextPerm=true;
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        for(int i=0;i<combinationLength;i++){
            this->bitString.push_back('0');
        }
        while(this->bitString.length() < this->characters.length()){
            this->bitString.push_back('1');
        }
        return;
    }
    
    string next() {
        string result = "";
        for(int i=0;i<this->characters.length();i++){
            if(this->bitString[i]=='0'){
                result.push_back(this->characters[i]);
            }
        }
        if(!next_permutation(bitString.begin(),bitString.end())){
            hasNextPerm=false;
        }
        return result;
    }
    
    bool hasNext() {
        return hasNextPerm;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */