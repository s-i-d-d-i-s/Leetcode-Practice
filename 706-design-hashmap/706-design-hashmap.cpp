#define N 152353

class MyHashMap {
public:
    list<pair<int,int>> hashTable[N];
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(contains(key)){
            remove(key);
        }
        hashTable[getHash(key)].push_back({key,value});
    }
    
    int get(int key) {
        for(auto x:hashTable[getHash(key)]){
            if(x.first == key){
                return x.second;
            }
        }
        return -1;
    }
    bool contains(int key){
        for(auto x:hashTable[getHash(key)]){
            if(x.first == key){
                return true;
            }
        }
        return false;
    }
    void remove(int key) {
        auto it = hashTable[getHash(key)].begin();
        while(it != hashTable[getHash(key)].end()){
            if((*it).first==key){
                break;
            }
            it++;
        }
        if(it != hashTable[getHash(key)].end()){
            hashTable[getHash(key)].erase(it);
        }
    }
    int getHash(int num){
        return num%N;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */