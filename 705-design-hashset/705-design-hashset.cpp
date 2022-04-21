#define N 152353
class MyHashSet {
public:
    list<int> hashTable[N];
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key))return;
        hashTable[getHash(key)].push_back(key);
    }
    
    void remove(int key) {
        auto it = hashTable[getHash(key)].begin();
        while(it != hashTable[getHash(key)].end()){
            if((*it)==key){
                break;
            }
            it++;
        }
        if(it != hashTable[getHash(key)].end()){
            hashTable[getHash(key)].erase(it);
        }
    }
    
    bool contains(int key) {
        for(int x:hashTable[getHash(key)]){
            if(x == key){
                return true;
            }
        }
        return false;
    }
    int getHash(int num){
        return num%N;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */