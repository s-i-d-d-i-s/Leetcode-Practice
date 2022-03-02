class LFUCache {
public:
    int maxCapacity;
    map<int,list<int>> freqList;
    map<int,int> freq;
    map<int,int> keyValue;
    map<int,list<int>::iterator> getNode;
    
    
    LFUCache(int capacity) {
        this->maxCapacity = capacity;
    }
    
    int get(int key) {
        if(keyValue.find(key)==keyValue.end()) return -1;
        int currentFreq = freq[key];
        int currentValue = keyValue[key];
        removeKey(key);
        insertKey(key,currentValue,currentFreq+1);
        return currentValue;
    }
    
    void put(int key, int value) {
        if(keyValue.find(key)==keyValue.end()){
            if(keyValue.size() == maxCapacity){
                removeLFU();
            }
            if(maxCapacity>0)
                insertKey(key,value,1);
        }else{
            int currentFreq = freq[key];
            int currentValue = keyValue[key];
            removeKey(key);
            insertKey(key,value,currentFreq+1);
        }
    }
    void removeLFU(){
        if(freqList.size() == 0)return;
        int minFreq = freqList.begin()->first;
        int LFUKey = *freqList[minFreq].begin();
        removeKey(LFUKey);
    }
    void removeKey(int key){
        auto node = getNode[key];
        int nodeFreq = freq[key];
        freqList[nodeFreq].erase(node);
        if(freqList[nodeFreq].size()==0)
            freqList.erase(nodeFreq);
        keyValue.erase(key);
        getNode.erase(key);
    }
    
    void insertKey(int key,int value,int freqValue){
        freqList[freqValue].push_back(key);
        freq[key]=freqValue;
        keyValue[key]=value;
        auto node = freqList[freqValue].end();
        node--;
        getNode[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */