class LRUCache {
public:
    list<int> cache;
    map<int,int> keyValue;
    map<int,list<int>::iterator> getNode;
    int maxLimit;
    
    // [] -> [] -> [] -> [] // Most Used
    LRUCache(int capacity) {
        this->maxLimit = capacity;
    }
    
    int get(int key) {
        if(keyValue.find(key) == keyValue.end()) return -1;
        int result = keyValue[key];
        removeKey(key);
        insertKey(key,result);
        return result;
    }
    
    void put(int key, int value) {
        if(keyValue.find(key) == keyValue.end()){
            if(cache.size() >= maxLimit){
                removeLRU();
            }
            insertKey(key,value);
            return;
        }
        removeKey(key);
        insertKey(key,value);
    }
    // Insert a Key
    
    void insertKey(int key,int value){
        cache.push_back(key);
        keyValue[key]=value;
        auto it = cache.end();
        it--;
        getNode[key]=it;
    }
    // Removes the LRU Key
    void removeLRU(){        
        int key = *cache.begin();
        removeKey(key);        
    }
    
    // Utility method to remove a particular key
    void removeKey(int key){
        auto it = getNode[key];        
        cache.erase(it);
        keyValue.erase(key);
        getNode.erase(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */