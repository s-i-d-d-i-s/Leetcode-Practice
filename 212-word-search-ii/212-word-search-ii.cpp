class TrieNode{
    public:
    TrieNode *child[26];
    bool isTerminal=false;
    TrieNode (){
        for(int i=0;i<26;i++) child[i] = nullptr;        
    }
    TrieNode * getChild(char a){
        return child[a-'a'];        
    }
    void addChild(char a){
        child[a-'a'] = new TrieNode();
    }
};
class Trie{
    public:
    TrieNode * root = new TrieNode();
    
    void addWord(string &a){
        TrieNode * cursor = root;        
        for(char x:a){
            if(cursor->getChild(x) == nullptr){
                cursor->addChild(x);
            }
            cursor = cursor->getChild(x);
        }
        cursor->isTerminal = true;
    }
    TrieNode * getRoot(){
        return root;
    }
};

class Solution {
public:
    set<string> result;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(auto x:words){
            trie.addWord(x);
        }
        auto root = trie.getRoot();
        
        int n = board.size(); int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string path;
                dfs(i,j,board,root,path);
            }
        }
        return {result.begin(),result.end()};
    }
    
    void dfs(int r,int c,vector<vector<char>> &board,TrieNode * root,string &path){
        int n = board.size(); int m = board[0].size();
        if(r<0 or r>=n or c<0 or c>=m or board[r][c]=='*') return;
        
        path.push_back(board[r][c]);
        
        if(root->getChild(board[r][c]) != nullptr){
            char currentChar = board[r][c];
            TrieNode * newRoot = root->getChild(board[r][c]);
            
            if(newRoot->isTerminal){
                result.insert(path);
            }
                
            board[r][c] = '*';
            
            dfs(r-1,c,board,newRoot,path);
            dfs(r+1,c,board,newRoot,path);
            dfs(r,c+1,board,newRoot,path);
            dfs(r,c-1,board,newRoot,path);
            
            board[r][c] = currentChar;
            
        }
        path.pop_back();
        return;        
    }
};