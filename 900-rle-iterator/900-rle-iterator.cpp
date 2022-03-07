class RLEIterator {
public:
    int index=0;
    int scanned=0;
    vector<int> encodedArray;
    
    RLEIterator(vector<int>& encoding) {
        this->encodedArray = encoding;    
    }
    
    int next(int n){
        /*
            Check if we are at a valid index
        */
        while(index<encodedArray.size() and 
              scanned == encodedArray[index]){
            index+=2;
            scanned=0;
        }
        if(index>=encodedArray.size()) return -1;       
        
        // How much element we have left on the current pointer
        int canHave = encodedArray[index]-scanned; 
        
        // How much element do we need to take from the current pointer
        int willHave = min(n,canHave);
        
        /*
            Two cases:
            1. we can take all 'n' elements at current pointer
            2. we can take all elements available at current pointer,
               but still we'll need more elements.
        */
        
        // Case #1
        if(willHave == n){
            int result = encodedArray[index+1];
            scanned+=willHave;        
            return result;
        }
        
        // Case #2
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