class TrieNode{
    public:
        unordered_map<char,TrieNode*> child;
        bool isTerminal;
        TrieNode(){
            isTerminal=false;
        }
};

class WordDictionary {
public:
    TrieNode * root;
    unordered_map<string,bool> cache;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * cursor = root;
        for(int i=0;i<word.length();i++){
            if(cursor->child[word[i]] == nullptr){
                cursor->child[word[i]] = new TrieNode();
            }
            cursor = cursor->child[word[i]];
        }
        cursor->isTerminal = true;
        cache.clear();
    }
    
    bool search(string word) {
        if(cache.find(word) != cache.end()) return cache[word];
        return  cache[word]=depthFirstSearch(0,word,root);
    }
    
    bool depthFirstSearch(int idx,string &a,TrieNode *cursor){
        if(idx>=a.length())return cursor->isTerminal;
        if(a[idx] == '.'){
            for(char c:"abcdefghijklmnopqrstuvwxyz"){
                if(cursor->child[c] != nullptr){
                    if(depthFirstSearch(idx+1,a,cursor->child[c]))return true;
                }
            }
            return false;
        }
        if(cursor->child[a[idx]] == nullptr) return false;
        return depthFirstSearch(idx+1,a,cursor->child[a[idx]]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */