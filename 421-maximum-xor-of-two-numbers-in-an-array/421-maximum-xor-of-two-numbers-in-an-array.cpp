class TrieNode{
    public:
    bool isTerminal=false;
    TrieNode * child[2];
    TrieNode(){
        child[0]=nullptr;
        child[1]=nullptr;
    }
};



class Solution {
public:
    TrieNode *root;
    
    void insertIntoTrie(int num){
        bitset<32> bits(num);
        TrieNode *cursor = root;
        
        for(int i=31;i>=0;i--){
            if(cursor->child[bits[i]] == nullptr){
                cursor->child[bits[i]] = new TrieNode();
            }
            cursor = cursor->child[bits[i]];
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(int x:nums){
            insertIntoTrie(x);
        }
        int result=0;
        for(int x:nums){
            result = max(result,getMaxXor(x));
        }
        return result;
    }
    
    int getMaxXor(int num){
        bitset<32> bits(num);
        TrieNode *cursor = root;
        int result=0;
        for(int i=31;i>=0;i--){
            if(cursor->child[!bits[i]] != nullptr){
                result += (1<<i);
                cursor = cursor->child[!bits[i]];
            }else{
                cursor = cursor->child[bits[i]];
            }
        }
        return result;
    }
};