class MagicDictionary {
public:
    vector<string> dictionary;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        this->dictionary=dictionary;
    }
    
    bool search(string searchWord) {
        for(auto x:dictionary){
            if(countMismatch(x,searchWord) == 1) return true;
        }
        return false;
    }
    int countMismatch(string &a,string &b){
        if(a.length() != b.length()) return -1;
        int result=0;
        for(int i=0;i<a.length();i++)
            if(a[i] != b[i]) result++;
        return result;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */