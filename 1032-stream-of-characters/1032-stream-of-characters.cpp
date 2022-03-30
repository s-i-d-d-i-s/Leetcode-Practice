class TrieNode{
    public:
    bool isTerminal;
    TrieNode * child[26];
    TrieNode(){
        for(int i=0;i<26;i++) child[i]=nullptr;
        isTerminal=false;
    }
};


class Trie{
  public:  
    TrieNode *root = new TrieNode();
    
    void addWord(string &a){
        TrieNode *cursor = root;
        int n = a.length();
        for(int i=n-1;i>=0;i--){
            if(cursor->child[a[i]-'a'] == nullptr){
                cursor->child[a[i]-'a'] = new TrieNode();
            }
            cursor=cursor->child[a[i]-'a'];
        }
        cursor->isTerminal=true;
    }
    
    bool getWord(string &a){
        int n = a.length();
        TrieNode *cursor = root;
        for(int i=n-1;i>=0;i--){
            if(cursor->child[a[i]-'a'] == nullptr){
                return false;
            }
            cursor=cursor->child[a[i]-'a'];
            if(cursor->isTerminal) return true;
        }
        return false;
    }
};



class StreamChecker {
public:
    Trie trie;
    string stream;
    StreamChecker(vector<string>& words) {
        for(auto x:words){
            trie.addWord(x);
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        return trie.getWord(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */