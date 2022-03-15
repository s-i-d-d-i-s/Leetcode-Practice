class TrieNode{
    public:
        TrieNode* child[26];
        bool isTerminal;
        TrieNode(){
            isTerminal=false;
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }
        }
};

class WordDictionary {
public:
    TrieNode * root;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * cursor = root;
        for(int i=0;i<word.length();i++){
            if(cursor->child[word[i]-'a'] == nullptr){
                cursor->child[word[i]-'a'] = new TrieNode();
            }
            cursor = cursor->child[word[i]-'a'];
        }
        cursor->isTerminal = true;
    }
    
    bool search(string word) {
        return depthFirstSearch(0,word,root);
    }
    
    bool depthFirstSearch(int idx,string &a,TrieNode *cursor){
        if(idx>=a.length())return cursor->isTerminal;
        if(a[idx] == '.'){
            for(char c='a';c<='z';c++){
                if(cursor->child[c-'a'] != nullptr){
                    if(depthFirstSearch(idx+1,a,cursor->child[c-'a']))return true;
                }
            }
            return false;
        }
        if(cursor->child[a[idx]-'a'] == nullptr) return false;
        return depthFirstSearch(idx+1,a,cursor->child[a[idx]-'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */