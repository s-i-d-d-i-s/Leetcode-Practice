class AllOne {
public:
    map<string,int> freq;
    multiset<pair<int,string>> ms;
    AllOne() {
        
    }
    
    void inc(string key) {
        freq[key]++;
        if(freq[key]==1){
            ms.insert({freq[key],key});
        }else{            
            ms.erase(ms.find({freq[key]-1,key}));
            ms.insert({freq[key],key});
        }
    }
    
    void dec(string key) {
        freq[key]--;
        if(freq[key]==0){
            ms.erase(ms.find({1,key}));
        }else{            
            ms.erase(ms.find({freq[key]+1,key}));
            ms.insert({freq[key],key});
        }
    }
    
    string getMaxKey() {
        return ms.size()>0?(--ms.end())->second:"";
    }
    
    string getMinKey() {
        return ms.size()>0?(ms.begin())->second:"";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */