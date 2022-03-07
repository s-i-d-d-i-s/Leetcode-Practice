class RLEIterator {
public:
    int index=0;
    int scanned=0;
    vector<int> encodedArray;
    
    RLEIterator(vector<int>& encoding) {
        this->encodedArray = encoding;    
    }
    
    int next(int n){
        while(index<encodedArray.size() and 
              scanned == encodedArray[index]){
            index+=2;
            scanned=0;
        }
        if(index>=encodedArray.size()) return -1;        
        int canHave = encodedArray[index]-scanned;
        int willHave = min(n,canHave);
        if(willHave == n){
            int result = encodedArray[index+1];
            scanned+=willHave;        
            return result;
        }
        scanned+=willHave;
        int result = next(n-willHave);        
        return result;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */